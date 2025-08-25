#ifndef AST_H
#define AST_H

// LIBRARY IMPORTS


// LOCAL IMPORTS
#include <token.h>

/*--------------------------------------------------------------------------------------------------------------------*/

typedef struct AST_NODE{

    token* attributes;
    struct AST_NODE* left;
    struct AST_NODE* right;

} astNode;


/*--------------------------------------------------------------------------------------------------------------------*/

astNode* newAstLeafNode(token* t);

astNode* newAstNode(token* t, astNode* left, astNode* right);

void deleteAstNode(astNode* node); // recursively frees the whole tree if called on root node

/*--------------------------------------------------------------------------------------------------------------------*/

#endif
