#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DataNode{
    char* data;
    struct DataNode* next;
}DataNode;

DataNode* createDataNode(char* data){
    DataNode* new_node = (DataNode*) malloc(sizeof(DataNode));
    new_node->data = (char*) malloc(strlen(data)+1);

    strcpy(new_node->data,data);
    new_node->next = NULL;

    return new_node;
}


int main() {
  char data[101];
  scanf("%[^\n]s", data);

  DataNode* pNew = createDataNode(data);

  printf("%s\n", pNew->data);
  printf("%p\n", (void*)pNew->next);

  return 0;
}
