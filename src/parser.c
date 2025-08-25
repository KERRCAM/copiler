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
    token* t = &tokens[1];
    ap->currToken = &t;
    return ap;

}

/*--------------------------------------------------------------------------------------------------------------------*/

void deleteAstPtr(astPtr* ap){

    free(ap);

}

/*--------------------------------------------------------------------------------------------------------------------*/

int getPrecedence(token* t){

    int p = precedence[*t->type];

    return p;

}

/*--------------------------------------------------------------------------------------------------------------------*/

void iterateAstPtr(astPtr* ap){

    ap->i++;
    token* t = &ap->tokens[ap->i];
    ap->currToken = &t;

}

/*--------------------------------------------------------------------------------------------------------------------*/

astNode* parseExpression(astPtr* ap, int preLvl, scanner* s){

    astNode* left = newAstLeafNode(newStaticToken(-1, EOF));
    astNode* parent = NULL;

    if (*(s->tokens[s->pos].type) == NUMBER){
        parent = newAstLeafNode(&s->tokens[s->pos]);
    } else {
        printf("ERROR: Invalid syntax at line %d\n", s->tokens[s->pos].line);
        exit(1);
    }

    iterateAstPtr(ap);
    s->pos++;

    if (*(s->tokens[s->pos].type) == EOF_TOKEN){ return parent;}

    if (getPrecedence(&s->tokens[s->pos]) > preLvl){
        *left = *parent;
        parent = newAstNode(&s->tokens[s->pos], left, NULL);
    } else {
        parent->left = newAstLeafNode(&s->tokens[s->pos]);
    }

    preLvl = getPrecedence(&s->tokens[s->pos]);
    iterateAstPtr(ap);
    s->pos++;
    parent->right = parseExpression(ap, preLvl, s);

    return parent;

}

/*--------------------------------------------------------------------------------------------------------------------*/

astNode* parser(astPtr* ap, scanner* s){

    // if (ap->tokens[ap->i].data == EOF_TOKEN){
    //     printf("WARNING: File is empty\n");
    //     exit(0);
    // }

    s->pos = 1;

    astNode* root = parseExpression(ap, -1, s);

    return root;


}

/*--------------------------------------------------------------------------------------------------------------------*/
