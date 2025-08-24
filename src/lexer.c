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

}

/*--------------------------------------------------------------------------------------------------------------------*/

void scanWhiteSpace(scanner* s){

    token* t = newToken(WHITESPACE);
    s->currToken = &t;

    while (isspace(s->currChar)){
        buildTokenData(*s->currToken, s->currChar);
        iterateScanner(s);
    }

    addToken(s, *s->currToken);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void scanInt(scanner* s){ // currently doing job of number (not currently accounting for non integers)

    token* t = newToken(NUMBER);
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

    token* t = newToken(WORD);
    s->currToken = &t;

    while (isalpha(s->currChar) || ispunct(s->currChar)){
        buildTokenData(*s->currToken, s->currChar);
        iterateScanner(s);
    }

    addToken(s, *s->currToken);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void scanUnknown(scanner* s){ // want to look into more latter but if chars can still be compared its okay for now

    token* t = newToken(UNKNOWN);
    s->currToken = &t;

    while (    isspace(s->currChar) == false
            && isdigit(s->currChar) == false
            && isalpha(s->currChar) == false
            && ispunct(s->currChar) == false){
        buildTokenData(*s->currToken, s->currChar);
        iterateScanner(s);
    }

    addToken(s, *s->currToken);
}

/*--------------------------------------------------------------------------------------------------------------------*/

void scanToken(scanner* s){

    while(s->currChar != EOF){
        if (isspace(s->currChar)){ scanWhiteSpace(s);}
        else if (isdigit(s->currChar)){ scanInt(s);}
        else if (isalpha(s->currChar) || ispunct(s->currChar)){ scanString(s);}
        else {scanUnknown(s);}
    }

}

/*--------------------------------------------------------------------------------------------------------------------*/

void lexer(scanner* s){

    scanToken(s);

}

/*--------------------------------------------------------------------------------------------------------------------*/