#ifndef AST_H
#define AST_H

// LIBRARY IMPORTS


// LOCAL IMPORTS
#include <token.h>

/*--------------------------------------------------------------------------------------------------------------------*/

typedef struct AST_NODE{

    token* attributes;
    astNode* left;
    astNode* right;

} astNode;


/*--------------------------------------------------------------------------------------------------------------------*/

astNode* newAstNode(token* t);
void deleteAstNode(astNode* node); // recursively frees the whole tree if called on root node

/*--------------------------------------------------------------------------------------------------------------------*/

#endif