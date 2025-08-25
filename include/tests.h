#ifndef TESTS_H
#define TESTS_H

// LIBRARY IMPORTS


// LOCAL IMPORTS
#include <lexer.h>
#include <parser.h>

/*--------------------------------------------------------------------------------------------------------------------*/

void lexerDebug(scanner* s);

void writeNode(astNode* node, int depth, FILE* fp);

void parserDebug(astNode* root);

/*--------------------------------------------------------------------------------------------------------------------*/

#endif
