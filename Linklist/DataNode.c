#include <string.h>
#include <stdio.h>
#include <stdlib.h>



typedef struct DataNode {
    char* data;
    struct DataNode* next;
}DataNode;

typedef struct SinglyLinklist {
    unsigned int count;
    struct DataNode* head;
}SinglyLinklist;

DataNode* createDataNode(char* data){
    
    DataNode* node = (DataNode*) malloc(sizeof(DataNode));
    node->data = malloc(sizeof(char)*(strlen(data)+1));
    node->next = NULL;

    strcpy(node->data,data);
    return node;
}

int main(){
    
    char* data;

    data = (char*) malloc(sizeof(char)*101);

    scanf(" %[^\n]", data);

    DataNode* new_node = createDataNode(data);

    printf("%s\n%p", new_node->data, new_node->next);

    return 0;

}