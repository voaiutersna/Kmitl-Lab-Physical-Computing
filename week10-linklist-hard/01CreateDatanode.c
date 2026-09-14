#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DataNode structure using typedef
typedef struct DataNode {
  char* data;
  struct DataNode* next;
} DataNode;

// Create a new DataNode
DataNode* createDataNode(char* data) {
  // Your code here
  DataNode* new_node = (DataNode*) malloc (sizeof(DataNode));
  new_node->data = (char*) malloc (strlen(data) + 1);
  strcpy((*new_node).data,data);
//   printf("%s",(*new_node).data);
//   (*new_node).next = NULL;

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