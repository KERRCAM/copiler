// LIBRARY IMPORTS
#include <stdlib.h>

// LOCAL IMPORTS
#include <ast.h>

/*--------------------------------------------------------------------------------------------------------------------*/

astNode* newAstLeafNode(token* t){

    astNode* node = calloc(1, sizeof(*node));

    node->attributes = t;
    node->left = NULL;
    node->right = NULL;

    return node;

}

/*--------------------------------------------------------------------------------------------------------------------*/

astNode* newAstNode(token* t, astNode* left, astNode* right){

    astNode* node = calloc(1, sizeof(*node));

    node->attributes = t;
    node->left = left;
    node->right = right;

    return node;

}

/*--------------------------------------------------------------------------------------------------------------------*/

void deleteAstNode(astNode* node){

    deleteToken(node->attributes);
    if (node->left != NULL){ deleteAstNode(node->left);}
    if (node->right != NULL){ deleteAstNode(node->right);}

    free(node);

}

/*--------------------------------------------------------------------------------------------------------------------*/
