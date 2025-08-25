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

    int p = precedence[t->type];

    return p;

}

/*--------------------------------------------------------------------------------------------------------------------*/

void iterateAstPtr(astPtr* ap){

    ap->i++;
    token* t = &ap->tokens[ap->i];
    ap->currToken = &t;

}

/*--------------------------------------------------------------------------------------------------------------------*/

astNode* parseExpression(astPtr* ap, int preLvl){

    astNode* left = newAstLeafNode(newStaticToken(-1, EOF));
    astNode* parent = NULL;

    if ((*ap->currToken)->type == NUMBER){
        parent = newAstLeafNode(*ap->currToken);
    } else {
        printf("err\n");
    }

    iterateAstPtr(ap);

    if ((*ap->currToken)->type == EOF_TOKEN){ return parent;}

    if (getPrecedence(*ap->currToken) > preLvl){
        *left = *parent;
        // printf("c: %s\n", parent->attributes->data);
        left->attributes->data[0] = 'H';
        // printf("c: %s\n", parent->attributes->data);
    } else {
        parent->left = newAstLeafNode(*ap->currToken);
    }

    // printf("SECOND P: %s, %d\n", parent->attributes->data, preLvl);
    // printf("SECOND L: %s, %d\n\n", parent->left->attributes->data, preLvl);

    preLvl = getPrecedence(*ap->currToken);
    iterateAstPtr(ap);
    parent->right = parseExpression(ap, preLvl);

    // printf("THIRD P: %s, %d\n", parent->attributes->data, preLvl);
    // printf("THIRD L: %s, %d\n", parent->right->attributes->data, preLvl);
    // printf("THIRD R: %s, %d\n\n", parent->left->attributes->data, preLvl);

    return parent;

}

/*--------------------------------------------------------------------------------------------------------------------*/

astNode* parser(astPtr* ap){

    printf("%d\n", (*ap->currToken)->type);

    if (ap->tokens[ap->i].data == EOF_TOKEN){
        printf("WARNING: File is empty\n");
        exit(0);
    }

    astNode* root = parseExpression(ap, -1);

    return root;


}

/*--------------------------------------------------------------------------------------------------------------------*/
