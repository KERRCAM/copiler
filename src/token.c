// LIBRARY IMPORTS
#include <stdio.h>
#include <stdlib.h>

// LOCAL IMPORTS
#include <token.h>

/*--------------------------------------------------------------------------------------------------------------------*/

token* newDynamicToken(int tokenType){

    token* t = calloc(1, sizeof(*t));

    t->tokenType = tokenType;
    t->tokenData = NULL;
    t->dataLength = 1;

    return t;

}

/*--------------------------------------------------------------------------------------------------------------------*/

token* newStaticToken(int tokenType, char tokenData){

    token* t = calloc(1, sizeof(*t));
    t->tokenData = calloc(1, sizeof(char));

    t->tokenType = tokenType;
    t->tokenData[0] = tokenData;
    t->dataLength = 1;

    return t;

}

/*--------------------------------------------------------------------------------------------------------------------*/


void deleteToken(token* t){

    free(t->tokenData);
    free(t);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void buildTokenData(token* t, char c){

    t->tokenData = realloc(t->tokenData, t->dataLength + 1);
    t->tokenData[t->dataLength - 1] = c;
    t->tokenData[t->dataLength] = '\0';
    t->dataLength++;

}

/*--------------------------------------------------------------------------------------------------------------------*/
