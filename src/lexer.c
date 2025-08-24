// LIBRARY IMPORTS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// LOCAL IMPORTS
#include <lexer.h>

/*--------------------------------------------------------------------------------------------------------------------*/

scanner* newScanner(char* input){

    scanner* s = calloc(1, sizeof(*s));

    s->input = input;
    s->tokens = calloc(1, sizeof(token));
    s->tokensSize = 1;
    s->lineNumber = 1;
    s->columnNumber = 0;

    return s;

}

/*--------------------------------------------------------------------------------------------------------------------*/

void deleteScanner(scanner* s){

    free(s->input);
    free(s->tokens);
    free(s);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void addToken(scanner* s, token* t){

    s->tokens = realloc(s->tokens, (s->tokensSize * sizeof(token)) + sizeof(token));
    s->tokens[s->tokensSize] = *t;
    s->tokensSize++;

}

/*--------------------------------------------------------------------------------------------------------------------*/

void iterateScanner(scanner* s){

    s->pos++;
    s->currChar = s->input[s->pos];
    s->columnNumber++;

}

/*--------------------------------------------------------------------------------------------------------------------*/

void skipWhiteSpace(scanner* s){

    while (isspace(s->currChar)){
        if (s->currChar == '\n'){ s->lineNumber++; s->columnNumber = 0;}
        iterateScanner(s);
    }

}

/*--------------------------------------------------------------------------------------------------------------------*/

void scanInt(scanner* s){ // currently doing job of number (not currently accounting for non integers)

    token* t = newDynamicToken(NUMBER);
    s->currToken = &t;

    while (isdigit(s->currChar)){
        buildTokenData(*s->currToken, s->currChar);
        iterateScanner(s);
    }

    addToken(s, *s->currToken);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void scanNumber(scanner* s){ // (not currently accounting for non integers so everything is going trough int scan rn)



}

/*--------------------------------------------------------------------------------------------------------------------*/

void scanString(scanner* s){

    token* t = newDynamicToken(WORD);
    s->currToken = &t;

    while (isalpha(s->currChar) || ispunct(s->currChar)){
        buildTokenData(*s->currToken, s->currChar);
        iterateScanner(s);
    }

    addToken(s, *s->currToken);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void scanToken(scanner* s){

    bool exit = false;

    while(s->currChar != EOF){
        switch (s->currChar){
            case '+':
                addToken(s, newStaticToken(PLUS, '+'));
                iterateScanner(s);
                break;
            case '-':
                addToken(s, newStaticToken(MINUS, '-'));
                iterateScanner(s);
                break;
            case '*':
                addToken(s, newStaticToken(MULTIPLY, '*'));
                iterateScanner(s);
                break;
            case '/':
                addToken(s, newStaticToken(DIVIDE, '/'));
                iterateScanner(s);
                break;
            default:
                if (isspace(s->currChar)){ skipWhiteSpace(s);}
                else if (isdigit(s->currChar)){ scanInt(s);}
                else{ exit = true;}
        }
        if (exit == true){
            printf("ERROR: Unrecognised character in line %d at column %d\n", s->lineNumber, s->columnNumber);
            break;
        }
    }

}

/*--------------------------------------------------------------------------------------------------------------------*/

void lexer(scanner* s){

    iterateScanner(s);
    scanToken(s);
    addToken(s, newStaticToken(EOF_TOKEN, EOF)); // End of tokens marker so a while loop can be used to iterate on it

}

/*--------------------------------------------------------------------------------------------------------------------*/