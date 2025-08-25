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

    if (*(s->tokens[ap->i].type) == NUMBER){
        parent = newAstLeafNode(&s->tokens[ap->i]);
    } else {
        printf("err\n");
    }

    iterateAstPtr(ap);

    if (*(s->tokens[ap->i].type) == EOF_TOKEN){ return parent;}

    if (getPrecedence(&ap->tokens[ap->i]) > preLvl){
        *left = *parent;
        // printf("c: %s\n", parent->attributes->data);
        //left->attributes->data[0] = 'H';
        parent = newAstNode(&ap->tokens[ap->i], left, NULL);
        // printf("c: %s\n", parent->attributes->data);
    } else {
        parent->left = newAstLeafNode(&ap->tokens[ap->i]);
    }

    // printf("SECOND P: %s, %d\n", parent->attributes->data, preLvl);
    // printf("SECOND L: %s, %d\n\n", parent->left->attributes->data, preLvl);

    preLvl = getPrecedence(&ap->tokens[ap->i]);
    iterateAstPtr(ap);
    parent->right = parseExpression(ap, preLvl, s);

    // printf("THIRD P: %s, %d\n", parent->attributes->data, preLvl);
    // printf("THIRD L: %s, %d\n", parent->right->attributes->data, preLvl);
    // printf("THIRD R: %s, %d\n\n", parent->left->attributes->data, preLvl);

    return parent;

}

/*--------------------------------------------------------------------------------------------------------------------*/

astNode* parser(astPtr* ap, scanner* s){
    printf("asd\n");
    printf("AA%d\n", *(s->tokens[1].type));
    printf("AA%d\n", *(s->tokens[2].type));
    printf("AA%d\n", *(s->tokens[3].type));
    printf("AA%d\n", *(s->tokens[4].type));
    printf("AA%d\n", *(s->tokens[1].type));
    printf("AA%d\n", *(s->tokens[1].type));
    printf("asd\n");

    // if (ap->tokens[ap->i].data == EOF_TOKEN){
    //     printf("WARNING: File is empty\n");
    //     exit(0);
    // }

    astNode* root = parseExpression(ap, -1, s);

    return root;


}

/*--------------------------------------------------------------------------------------------------------------------*/
