#ifndef TOKEN_H
#define TOKEN_H

// LIBRARY IMPORTS


// LOCAL IMPORTS


/*--------------------------------------------------------------------------------------------------------------------*/

enum tokenType{
    WHITESPACE,
    WORD,
    NUMBER,
    UNKNOWN,
};

/*--------------------------------------------------------------------------------------------------------------------*/

typedef struct TOKEN{

    int tokenType;
    int dataLength;
    char* tokenData;

} token;

/*--------------------------------------------------------------------------------------------------------------------*/

token* newToken(int tokentype);

void deleteToken(token* t);

void buildTokenData(token* t, char c);

/*--------------------------------------------------------------------------------------------------------------------*/

#endif