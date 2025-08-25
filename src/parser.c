// LIBRARY IMPORTS
#include <stdio.h>
#include <stdlib.h>

// LOCAL IMPORTS
#include <parser.h>

/*--------------------------------------------------------------------------------------------------------------------*/

astPtr* newAstPtr(token* tokens){

    astPtr* ap = calloc(1, sizeof(*ap));

    ap->tokens = tokens;
    ap->i = 1;

    return ap;

}

/*--------------------------------------------------------------------------------------------------------------------*/

void deleteAstPtr(astPtr* ap){

    free(ap);

}

/*--------------------------------------------------------------------------------------------------------------------*/

int getPrecedence(astPtr* ap, int tokenType){

    int p = precedence[tokenType];

    if (p == 0){
        printf("data: %s\n", ap->tokens[ap->i].data);
        printf("ERROR: Invalid syntax on line %d (GP)\n", ap->tokens[ap->i].line);
        exit(1);
    }

    return p;

}

/*--------------------------------------------------------------------------------------------------------------------*/

astNode* parsePrimary(astPtr* ap){

    astNode* node;

    if (ap->tokens[ap->i].type != NUMBER){
        printf("ERROR: Invalid syntax on line %d (PP)\n", ap->tokens[ap->i].line);
        exit(1);
    }

    node = newAstLeafNode(&ap->tokens[ap->i]);
    ap->i++;

    return node;

}

/*--------------------------------------------------------------------------------------------------------------------*/

astNode* parseExpression(astPtr* ap, int preLvl){

    astNode* left;
    astNode* right;

    left = parsePrimary(ap);

    if (ap->tokens[ap->i].data == EOF_TOKEN){
        return left;
    }

    while(getPrecedence(ap, ap->tokens[ap->i].type) > preLvl){

        ap->i++;

        right = parseExpression(ap, precedence[ap->tokens[ap->i].type]);

        left = newAstNode(&ap->tokens[ap->i], left, right);

        if (ap->tokens[ap->i].data == EOF_TOKEN){
            return left;
        }

    }

    return left;

}

/*--------------------------------------------------------------------------------------------------------------------*/

astNode* parser(astPtr* ap){

    if (ap->tokens[ap->i].data == EOF_TOKEN){
        printf("WARNING: File is empty\n");
        exit(0);
    }

    astNode* root = parseExpression(ap, precedence[ap->tokens[ap->i].type]);

    return root;

}

/*--------------------------------------------------------------------------------------------------------------------*/
