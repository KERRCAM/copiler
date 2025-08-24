// LIBRARY IMPORTS


// LOCAL IMPORTS
#include <ast.h>

/*--------------------------------------------------------------------------------------------------------------------*/

newAstNode* astNode(token* t){

    astNode* node = calloc(1, sizeof(*node));

    node->attributes = t;
    node->left = NULL;
    node->RIGHT = NULL;

    return node;

}

/*--------------------------------------------------------------------------------------------------------------------*/

void deleteAstNode(astNode* node){

    deleteToken(node->attributes);
    if (node->left != NULL){ deleteAstNode(node->left);}
    if (node->right !- NULL){ deleteAstNode(node->right);}

    free(node);

}

/*--------------------------------------------------------------------------------------------------------------------*/
