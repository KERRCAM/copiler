#ifndef PARSER_H
#define PARSER_H

// LIBRARY IMPORTS


// LOCAL IMPORTS
#include <ast.h>

/*--------------------------------------------------------------------------------------------------------------------*/

static int precedence[] = {
    0, // EOF_TOKEN
    0, // NUMBER
    1, // PLUS
    1, // MINUS
    2, // MULTIPLY
    2, // DIVIDE
};

/*--------------------------------------------------------------------------------------------------------------------*/

typedef struct AST_POINTER{

    int i;
    token* tokens;

} astPtr;

/*--------------------------------------------------------------------------------------------------------------------*/

astPtr* newAstPtr(token* tokens);

void deleteAstPtr(astPtr* ap);

int getPrecedence(astPtr* ap, int tokenType);

astNode* parsePrimary(astPtr* ap);

astNode* parseExpression(astPtr* ap, int preLvl);

astNode* parser(astPtr* ap);

/*--------------------------------------------------------------------------------------------------------------------*/

#endif
