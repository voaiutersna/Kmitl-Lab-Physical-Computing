#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DataNode structure using typedef
// โหนด 1 ตัว = กล่องที่เก็บ "ข้อมูล" + "ลูกศรชี้ไปโหนดถัดไป"
typedef struct DataNode {
  char* data;               // ข้อความที่เก็บในโหนด
  struct DataNode* next;    // ชี้ไปโหนดถัดไป (ถ้าเป็นตัวสุดท้ายจะเป็น NULL)
} DataNode;

// SinglyLinkedList structure using typedef
// ตัว list เก็บแค่ "หัว" (โหนดแรก) กับ "จำนวนโหนด"
typedef struct SinglyLinkedList {
  unsigned int count;       // จำนวนโหนดทั้งหมดใน list
  DataNode* head;           // ชี้ไปโหนดแรก (ถ้า list ว่างจะเป็น NULL)
} SinglyLinkedList;

// Create a new DataNode
DataNode* createDataNode(char* data) {
  // จองหน่วยความจำให้โหนด 1 ตัว
  DataNode* new_node = (DataNode*) malloc(sizeof(DataNode));

  // จองหน่วยความจำให้ข้อความ (+1 สำหรับ '\0' ตัวปิดท้าย string) แล้ว copy เข้าไป
  new_node->data = (char*) malloc(strlen(data) + 1);
  strcpy(new_node->data, data);

  // สำคัญมาก! ต้องตั้ง next = NULL เสมอ
  // ไม่งั้น next จะเป็นค่าขยะ แล้ว while (pointer->next != NULL) จะวิ่งไปที่มั่วๆ จน crash
  new_node->next = NULL;

  return new_node;
}

// Create a new SinglyLinkedList
SinglyLinkedList* createSinglyLinkedList() {
  SinglyLinkedList* new_list = (SinglyLinkedList*) malloc(sizeof(SinglyLinkedList));
  new_list->count = 0;      // ตอนเริ่มยังไม่มีโหนด
  new_list->head = NULL;    // หัวยังไม่ชี้ไปไหน
  return new_list;
}

// Insert a new node at the end of the list
void insert_last(SinglyLinkedList* list, char* data) {
  DataNode* pNew = createDataNode(data);

  if (list->head == NULL) {
    // กรณี list ว่าง -> โหนดใหม่คือโหนดแรก ให้ head ชี้ไปที่มันเลย
    list->head = pNew;
  } else {
    // กรณี list ไม่ว่าง -> เดินจาก head ไปเรื่อยๆ จนเจอโหนดสุดท้าย
    // (โหนดสุดท้าย คือโหนดที่ next == NULL)
    DataNode* pointer = list->head;
    while (pointer->next != NULL) {
      pointer = pointer->next;   // ขยับไปโหนดถัดไป
    }
    // ตอนนี้ pointer อยู่ที่โหนดสุดท้ายแล้ว -> ต่อโหนดใหม่เข้าไปข้างหลัง
    pointer->next = pNew;
  }

  list->count++;  // เพิ่มจำนวนโหนด
}

// Traverse the list and print data
// ปริ้นทุกโหนดตั้งแต่หัวจนท้าย เช่น  A -> B -> C
void traverse(SinglyLinkedList* list) {
  if (list->head == NULL) {
    printf("This is an empty list.\n");
    return;
  }

  DataNode* pointer = list->head;
  while (pointer != NULL) {
    printf("%s", pointer->data);
    if (pointer->next != NULL) {
      printf(" -> ");            // ใส่ลูกศรเฉพาะถ้ายังมีโหนดถัดไป
    }
    pointer = pointer->next;
  }
  printf("\n");
}

// Traverse by index: หาโหนดที่ตำแหน่ง index (เริ่มนับจาก 0)
// คืนค่า pointer ไปที่โหนดนั้น หรือ NULL ถ้า index ไม่มีอยู่จริง
DataNode* get_node_at(SinglyLinkedList* list, int index) {
  // เช็คก่อนว่า index อยู่ในช่วง 0 ถึง count-1 ไหม
  // (linked list กระโดดไปตำแหน่งตรงๆ แบบ array[i] ไม่ได้ ต้องเดินทีละโหนด)
  if (index < 0 || index >= (int) list->count) {
    return NULL;
  }

  DataNode* pointer = list->head;   // เริ่มที่โหนด index 0
  for (int i = 0; i < index; i++) {
    pointer = pointer->next;        // เดินไป 1 ก้าว = index เพิ่มขึ้น 1
  }
  // เดินครบ index ก้าวแล้ว pointer อยู่ที่โหนดที่ต้องการพอดี
  return pointer;
}

// ปริ้นข้อมูลของโหนดที่ index ที่กำหนด
void traverse_by_index(SinglyLinkedList* list, int index) {
  DataNode* node = get_node_at(list, index);
  if (node == NULL) {
    printf("Index out of range.\n");
  } else {
    printf("%s\n", node->data);
  }
}

int main() {
  SinglyLinkedList* mylist = createSinglyLinkedList();
  int n, index;
  char condition;
  char data[101];

  // รับจำนวนคำสั่ง แล้วรับคำสั่งรูปแบบ "L: ข้อความ"
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf(" %c: %[^\n]", &condition, data);
    if (condition == 'L') {
      insert_last(mylist, data);
    } else {
      printf("Invalid Condition!\n");
    }
  }

  // รับ index ที่ต้องการดู
  scanf("%d", &index);

  traverse(mylist);                   // ปริ้นทั้ง list
  traverse_by_index(mylist, index);   // ปริ้นเฉพาะโหนดที่ index

  // คืนหน่วยความจำ: ต้อง free ทั้ง data และตัวโหนด
  // ต้องเก็บ next ไว้ก่อน free เพราะ free แล้วจะอ่าน current->next ไม่ได้อีก
  DataNode* current = mylist->head;
  while (current != NULL) {
    DataNode* temp = current;
    current = current->next;
    free(temp->data);
    free(temp);
  }
  free(mylist);
  return 0;
}
