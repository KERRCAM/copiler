#ifndef LEXER_H
#define LEXER_H

// LIBRARY IMPORTS


// LOCAL IMPORTS
#include <token.h>

/*--------------------------------------------------------------------------------------------------------------------*/

typedef struct SCANNER{

    int pos;
    char currChar;
    char* input;
    int tokensSize;
    int lineNumber;
    int columnNumber;
    token** currToken;
    token* tokens;

} scanner;

/*--------------------------------------------------------------------------------------------------------------------*/

scanner* newScanner(char* input);

void deleteScanner(scanner* s);

void addToken(scanner* s, token* t);

void iterateScanner(scanner* s);

void skipWhiteSpace(scanner* s);

void scanInt(scanner* s);

void scanNumber(scanner* s);

void scanToken(scanner* s);

void lexer(scanner* s);

/*--------------------------------------------------------------------------------------------------------------------*/

#endif