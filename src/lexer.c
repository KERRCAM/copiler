// LIBRARY IMPORTS
#include <stdio.h>
#include <stdlib.h>

// LOCAL IMPORTS
#include <lexer.h>

/*--------------------------------------------------------------------------------------------------------------------*/

char* readInput(char* path){


    FILE* fp = fopen(path, "rb");

    char* input = malloc(1);

    int c;
    int i = 0;

    while((c = fgetc(fp)) != EOF){
        input[i] = c;
        i++;
        input = realloc(input, i + 1);
    }

    return input;

}

/*--------------------------------------------------------------------------------------------------------------------*/


iterateScanner(scanner* s){

    s->pos++;
    s->currChar = s->input[pos];

}

/*--------------------------------------------------------------------------------------------------------------------*/

void skipWhiteSpace(scanner* s){

    while (s->currChar == ' ' || s->currChar == '\n' || s->currChar == '\r' || s->currChar == '\t'){

        if (s->currChar == '\n'){ s->line++;}
        iterateScanner(s);

    }

}

/*--------------------------------------------------------------------------------------------------------------------*/

void lexer(){

    scanner* s = calloc(1, sizeof(*s));

}

/*--------------------------------------------------------------------------------------------------------------------*/
