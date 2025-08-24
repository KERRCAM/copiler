#ifndef TOKEN_H
#define TOKEN_H

// LIBRARY IMPORTS


// LOCAL IMPORTS


/*--------------------------------------------------------------------------------------------------------------------*/

enum tokenType{
    WHITESPACE,
    WORD,
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
};

/*--------------------------------------------------------------------------------------------------------------------*/

typedef struct TOKEN{

    int tokenType;
    int dataLength;
    char* tokenData;

} token;

/*--------------------------------------------------------------------------------------------------------------------*/

token* newDynamicToken(int tokentype);

token* newStaticToken(int tokentype, char tokenData);

void deleteToken(token* t);

void buildTokenData(token* t, char c);

/*--------------------------------------------------------------------------------------------------------------------*/

#endif