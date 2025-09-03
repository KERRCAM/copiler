#ifndef GENERATOR_H
#define GENERATOR_H

// LIBRARY IMPORTS


// LOCAL IMPORTS
#include <ast.h>

/*--------------------------------------------------------------------------------------------------------------------*/



/*--------------------------------------------------------------------------------------------------------------------*/

void freeRegister(char* reg);

char* popRegister();

void setup(FILE* fp);

void postOrderSearch(astNode* node);

void generateAssembly(char* path, astNode* root);

/*--------------------------------------------------------------------------------------------------------------------*/

#endif
