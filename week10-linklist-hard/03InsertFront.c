#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DataNode structure using typedef
typedef struct DataNode {
  char* data;
  struct DataNode* next;
} DataNode;

// SinglyLinkedList structure using typedef
typedef struct SinglyLinkedList {
  unsigned int count;
  DataNode* head;
} SinglyLinkedList;

// Create a new DataNode
DataNode* createDataNode(char* data) {
  // Your code here
  DataNode* new_node = (DataNode*) malloc (sizeof(DataNode));
  new_node->data = (char*) malloc (strlen(data) + 1);
  strcpy((*new_node).data,data);

  return new_node;
}

// Create a new SinglyLinkedList
SinglyLinkedList* createSinglyLinkedList() {
    SinglyLinkedList* new_linklist = (SinglyLinkedList*) malloc (sizeof(SinglyLinkedList));
    (*new_linklist).count = 0;
    return new_linklist;
}

// Traverse the list and print data
void traverse(SinglyLinkedList* list) {
    if (list->count == 0) {
        printf("This is an empty list.\n");
        return;
    }
    struct DataNode* pointer = list->head;
    while (pointer->next != NULL) {
        printf("%s -> ", pointer->data);
        pointer = (*pointer).next; // ปริ้นข้อมูลและขยับ pointer ไปเรื่อยๆ จนถึงโหนดตัวสุดท้าย
    }
    printf("%s\n", pointer->data);
}

// Insert a new node at the end of the list
void insert_last(SinglyLinkedList* list, char* data) {
    struct DataNode* pNew = createDataNode(data);
    if (list->count == 0) {
        (*list).head =  pNew;// ถ้า Linked List ว่างให้เปลี่ยนตำแหน่ง list->head ไปที่ pNew
    } else {
        // ถ้า Linked List ไม่ว่างให้สร้าง Pointer ตัวใหม่และขยับไปที่โหนดสุดท้ายและเปลี่ยน pointer->next เป็น pNew
        struct DataNode* pointer = (*list).head;
        while (pointer->next != NULL) {
            pointer = (*pointer).next;
        }
        (*pointer).next = pNew;
    }
    list->count++;
    // printf("count: %u\n",list->count);

}

void insert_front(SinglyLinkedList* list, char* data) {
    struct DataNode* pNew = createDataNode(data);
    if (list->count == 0) {
        (*list).head =  pNew;// ถ้า Linked List ว่างให้เปลี่ยนตำแหน่ง list->head ไปที่ pNew
    } else {
        (*pNew).next = (*list).head;
        (*list).head =  pNew;
    }
    (*list).count += 1;
}

int main() {
    SinglyLinkedList* mylist = createSinglyLinkedList();
    int n;
    char condition;
    char data[100]; 
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %c: %[^\n]s", &condition, data); 
        if (condition == 'F') {
            insert_front(mylist, data);
        } else if (condition == 'L') {
            insert_last(mylist, data);
        } else if (condition == 'D') {
            ;
        } else {
            printf("Invalid Condition!\n");
        }
    }

    traverse(mylist);
    // Remember to free allocated memory for each node's data
    DataNode* current = mylist->head;
    while (current != NULL) {
        free(current->data);
        DataNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(mylist);
    return 0;
}