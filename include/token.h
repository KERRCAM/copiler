#ifndef TOKEN_H
#define TOKEN_H

// LIBRARY IMPORTS


// LOCAL IMPORTS


/*--------------------------------------------------------------------------------------------------------------------*/

enum tokenType{
    EOF_TOKEN,
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
};

/*--------------------------------------------------------------------------------------------------------------------*/

typedef struct TOKEN{

    int* type;
    int dataLength;
    char* data;
    int line;

} token;

/*--------------------------------------------------------------------------------------------------------------------*/

token* newDynamicToken(int type);

token* newStaticToken(int type, char data);

void deleteToken(token* t);

void buildTokenData(token* t, char c);

/*--------------------------------------------------------------------------------------------------------------------*/

#endif