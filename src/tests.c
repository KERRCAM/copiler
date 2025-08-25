// LIBRARY IMPORTS
#include <stdio.h>

// LOCAL IMPORTS
#include <tests.h>

/*--------------------------------------------------------------------------------------------------------------------*/

void lexerDebug(scanner* s){

    FILE* fp = fopen("debug/lexerOutput", "w");

    for (int i = 0; i < s->tokensSize; i++){
        fprintf(fp, "Type: %d  |  Data: %s\n", *(s->tokens[i].type), s->tokens[i].data);
    }

    fclose(fp);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void writeNode(astNode* node, int depth, FILE* fp){

    if (node == NULL){ return;}

    fprintf(fp, "Data: %s  |  Depth: %d\n", node->attributes->data, depth);
    depth++;
    writeNode(node->left, depth, fp);
    writeNode(node->right, depth, fp);

}

/*--------------------------------------------------------------------------------------------------------------------*/

void parserDebug(astNode* root){

    FILE* fp = fopen("debug/parserOutput", "w");

    writeNode(root, 0, fp);

    fclose(fp);

}

/*--------------------------------------------------------------------------------------------------------------------*/
