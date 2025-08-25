// LIBRARY IMPORTS
#include <stdio.h>
#include <stdlib.h>

// LOCAL IMPORTS
#include <lexer.h>
#include <parser.h>
#include <tests.h>

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

    input[i] = EOF;

    return input;

}

/*--------------------------------------------------------------------------------------------------------------------*/

int main(){

    char* srcPath = "testFiles/singleExp.txt";
    char* input = readInput(srcPath);

    scanner* s = newScanner(input);
    lexer(s);
    lexerDebug(s);

    astPtr* ap = newAstPtr(s->tokens);
    astNode* root = parser(ap);
    parserDebug(root);

    deleteScanner(s);

    return 0;

}

/*--------------------------------------------------------------------------------------------------------------------*/
