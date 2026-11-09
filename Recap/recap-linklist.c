#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DataNode {
    char* data;
    struct DataNode* next;
}DataNode;

typedef struct Signlylinklist {
    unsigned int count;
    struct DataNode* head;
}Signlylinklist;

DataNode* createDataNode(char* data){

    //create DataNode
    DataNode* node = (DataNode*) malloc(sizeof(DataNode));
    
    //data is string so malloc for storage of string
    node->data = (char*) malloc(sizeof(char)*(strlen(data)+1));
    node->next = NULL;

    //acopy data to inside storage heap of data node
    strcpy(node->data,data);

    return node;

}



int main(){
    char data[101];
    scanf(" %[^\n]", data);

    DataNode* node = createDataNode(data);
    printf("%s\n", node->data);
    printf("%p\n", node->next);

    return 0;

}