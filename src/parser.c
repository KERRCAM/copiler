// LIBRARY IMPORTS
#include <stdio.h>
#include <stdlib.h>

// LOCAL IMPORTS
#include <parser.h>

/*--------------------------------------------------------------------------------------------------------------------*/

int getPrecedence(token* t){

    int p = precedence[*t->type];

    return p;

}

/*--------------------------------------------------------------------------------------------------------------------*/

astNode* parseExpressionOLD(scanner* s, int preLvl){ // TODO - logic for this func needs some re thinking

    astNode* left = newAstLeafNode(newStaticToken(-1, EOF));
    astNode* parent = NULL;

    if (*(s->tokens[s->pos].type) == NUMBER){
        parent = newAstLeafNode(&s->tokens[s->pos]);
    } else {
        printf("ERROR: Invalid syntax at line %d\n", s->tokens[s->pos].line);
        exit(1);
    }

    s->pos++;

    if (*(s->tokens[s->pos].type) == EOF_TOKEN){ return parent;}

    if (getPrecedence(&s->tokens[s->pos]) > preLvl){
        *left = *parent;
        parent = newAstNode(&s->tokens[s->pos], left, NULL);
    } else {
        parent->left = newAstLeafNode(&s->tokens[s->pos]);
    }

    preLvl = getPrecedence(&s->tokens[s->pos]);
    s->pos++;
    parent->right = parseExpression(s, preLvl);

    return parent;

}

astNode* parseExpression(scanner* s, int preLvl){

    astNode* left = newAstLeafNode(newStaticToken(-1, EOF));
    astNode* parent = NULL;

    if (*(s->tokens[s->pos].type) == NUMBER){
        left = newAstLeafNode(&s->tokens[s->pos]);
    } else {
        printf("ERROR: Invalid syntax at line %d\n", s->tokens[s->pos].line);
        exit(1);
    }

    s->pos++;

    if (getPrecedence(&s->tokens[s->pos]) > preLvl){

    }

}

/*--------------------------------------------------------------------------------------------------------------------*/

astNode* parser(scanner* s){

    s->pos = 1;

    if (s->tokens[s->pos].data == EOF_TOKEN){
        printf("WARNING: File is empty\n");
        exit(0);
    }

    astNode* root = parseExpression(s, 1);

    return root;

}

/*--------------------------------------------------------------------------------------------------------------------*/

/*

t1 should be num
if t2 add -> go forward

t1 should be num
if t2 is x -> go forward
t3 should num
if t4 add then 

*/