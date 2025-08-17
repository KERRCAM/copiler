#ifndef LEXER_H
#define LEXER_H
// LIBRARY IMPORTS


// LOCAL IMPORTS


/*--------------------------------------------------------------------------------------------------------------------*/
// STRUCTS

typedef struct SCANNER{

    int pos;
    int line;
    char currChar;
    char* input;

} scanner;

/*--------------------------------------------------------------------------------------------------------------------*/
// FUNCTIONS

char* readInput(char* path);

scanner* newScanner(char* path);

void deleteScanner(scanner* s);

void iterateScanner(scanner* s);

void skipWhiteSpace(scanner* s);

void lexicalScan();

/*--------------------------------------------------------------------------------------------------------------------*/

#endif