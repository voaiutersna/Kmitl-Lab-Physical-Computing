#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
  new_node->next = NULL;

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

void delete(struct SinglyLinkedList* list, char* data) {
    bool isdelete = false;
    if (list->count == 0) {
        printf("Cannot delete, %s does not exist.\n", data);
        return;
    }
    struct DataNode* current = list->head;
    // struct DataNode* previous = NULL;
    if(!strcmp((*current).data,data)){ //กรณี target อยู่ head
        list->head =  (*current).next;
        isdelete = true;
        list->count--;
    }

    if (!isdelete && current->next != NULL) { // ถ้าลบ head ไปแล้ว (isdelete=true) ก็หยุดเลย ไม่ต้องหาต่อ กันลบซ้ำตอนมีข้อมูลซ้ำในลิสต์ // กันกรณีลิสต์เหลือโหนดเดียว current->next จะเป็น NULL ห้ามเข้าไป dereference ต่อ
        while ((*((*current).next)).next != NULL) {
            if(!strcmp((*((*current).next)).data ,data)){
                (*current).next =  (*((*current).next)).next;
                list->count--;
                isdelete = true;
                break;
            }
            // printf("Current: %s", current->data);
            current = (*current).next; // ขยับ current ไปเรื่อยๆ จนถึงโหนดตัวก่อนสุดท้าย
        }

        if(!strcmp((*((*current).next)).data,data)){ //กรณี target อยู่สุดท้าย
            (*current).next = NULL;
            list->count--;
            isdelete = true;
        }
    }

    if(!isdelete){
        printf("Cannot delete, %s does not exist.\n", data);
    }
    
}

int main() {
    SinglyLinkedList* mylist = createSinglyLinkedList();
    int n;
    char condition;
    char data[100]; // Assuming a maximum string length of 99 characters
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %c: %[^\n]s", &condition, data); // Read condition and string data

        if (condition == 'F') {
            insert_front(mylist, data);
        } else if (condition == 'L') {
            insert_last(mylist, data);
        } else if (condition == 'D') {
            delete(mylist, data);
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