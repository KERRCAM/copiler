// LIBRARY IMPORTS


// LOCAL IMPORTS
#include <generator.h>
#include <ast.h>

/*--------------------------------------------------------------------------------------------------------------------*/

// resisters arr (useful as a queue (or stack)? -> pop off to use, put back when done)
// ops arr

/*--------------------------------------------------------------------------------------------------------------------*/

void exp(int operator, char* arg, char* arg); // construct asm expr

/*--------------------------------------------------------------------------------------------------------------------*/

void postOrderSearch(astNode* node){ // will give us left arg, right arg then op going bottom to top of tree

    if (node->right == NULL){}

}

/*--------------------------------------------------------------------------------------------------------------------*/
