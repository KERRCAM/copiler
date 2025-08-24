// LIBRARY IMPORTS
#include <stdio.h>
#include <stdlib.h>

// LOCAL IMPORTS
#include <token.h>

/*--------------------------------------------------------------------------------------------------------------------*/

token* newDynamicToken(int type){

    token* t = calloc(1, sizeof(*t));

    t->type = type;
    t->data = NULL;
    t->dataLength = 1;

    return t;

}

/*--------------------------------------------------------------------------------------------------------------------*/

token* newStaticToken(int type, char data){

    token* t = calloc(1, sizeof(*t));
    t->data = calloc(1, sizeof(char));

    t->type = type;
    t->data[0] = data;
    t->dataLength = 1;

    return t;

}

/*--------------------------------------------------------------------------------------------------------------------*/


void deleteToken(token* t){

    free(t->data);
    free(t);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void buildTokenData(token* t, char c){

    t->data = realloc(t->data, t->dataLength + 1);
    t->data[t->dataLength - 1] = c;
    t->data[t->dataLength] = '\0';
    t->dataLength++;

}

/*--------------------------------------------------------------------------------------------------------------------*/
