// LIBRARY IMPORTS
#include <stdio.h>
#include <stdlib.h>

// LOCAL IMPORTS
#include <generator.h>

/*--------------------------------------------------------------------------------------------------------------------*/

// resisters arr (useful as a queue (or stack)? -> pop off to use, put back when done)
// ops arr

int stackPointer = 30;
int stackSize = 30;

char* registers[31] = { // The general registers
    "X0",
    "X1",
    "X2",
    "X3",
    "X4",
    "X5",
    "X6",
    "X7",
    "X8",
    "X9",
    "X10",
    "X11",
    "X12",
    "X13",
    "X14",
    "X15",
    "X16",
    "X17",
    "X18",
    "X19",
    "X20",
    "X21",
    "X22",
    "X23",
    "X24",
    "X25",
    "X26",
    "X27",
    "X28",
    "X29",
    "X30",
};

char* opcodes[10] = {
    ""
};

/*--------------------------------------------------------------------------------------------------------------------*/

void freeRegister(char* reg){

    registers[stackPointer] = reg;

}

/*--------------------------------------------------------------------------------------------------------------------*/

char* popRegister(){

    return registers[stackPointer];

}

/*--------------------------------------------------------------------------------------------------------------------*/

void setup(FILE* fp){

    fprintf(fp, ".global _start\n_start:");

}

/*--------------------------------------------------------------------------------------------------------------------*/

void asmExpression(int operator, char* arg1, char* arg2); // construct asm expr

/*--------------------------------------------------------------------------------------------------------------------*/

void postOrderSearch(astNode* node){ // will give us left arg, right arg then op going bottom to top of tree

    if (node->right == NULL){
        // load value into reg on top of stack
        // return reg
        return;
    }



}

/*--------------------------------------------------------------------------------------------------------------------*/

void generateAssembly(char* path, astNode* root){

    FILE* fp = fopen(path, "w");

    setup(fp);


}

/*--------------------------------------------------------------------------------------------------------------------*/

/* get result

if number then result is reg number is loaded into

if operator then result is reg result was written too


*/