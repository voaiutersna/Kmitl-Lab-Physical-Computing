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

SinglyLinklist* createSignlyLinklist(){
    
    SinglyLinklist* list = (SinglyLinklist*) malloc(sizeof(SinglyLinklist));
    
    //default
    list->count = 0;
    list->head = NULL;

    return list;
}

void insert_last(SinglyLinklist* list,char* data){

    DataNode* node = createDataNode(data);

    if(list->head == NULL){
        list->head = node;
        list->count += 1;
    }else{
        DataNode* curr = list->head;
        
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = node;
        list->count += 1;
    }

}

void insert_front(SinglyLinklist* list, char* data){
    
    DataNode* node = createDataNode(data);
    
    //head is null
    if(list->head == NULL){
        list->head = node;
        list->count += 1;
        return;
    }else{
        DataNode* prev_head = list->head;
        list->head = node;
        node->next = prev_head;
        list->count += 1;
        return;
    }
}

void delete(SinglyLinklist* list, char* data){
    
    //Empty list
    if(list->head == NULL || (strcmp(list->head->data,data) && list->count == 1)){
        printf("Cannot delete, %s does not exist.\n", data);
        return;
    }

    //Delete head
    if(!strcmp(list->head->data,data)){
        list->head = list->head->next;
        list->count -= 1;
        return;
    }


    DataNode* prev = list->head;
    DataNode* curr = list->head->next;

    while(curr->next != NULL){
        if(!strcmp(curr->data,data)){
            prev->next = curr->next;
            list->count -= 1;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    if(!strcmp(curr->data,data)){
        prev->next = NULL;
        list->count -= 1;
        return;
    }
    printf("Cannot delete, %s does not exist.\n", data);

}

void traverse(SinglyLinklist* list){

    if(list->head == NULL){
        printf("This is an empty list.\n");
        return;
    }

    DataNode* curr = list->head;

    while(curr->next != NULL){
        printf("%s", curr->data);
        printf(" -> ");
        curr = curr->next;
    }
    printf("%s\n", curr->data);

}

void traverse_index(SinglyLinklist* list, int n){

    if(n<0){
        n += (int) list->count;
    }
    if(n<0 || n>= (int)list->count || list->head == NULL){
        printf("Error\n");
        return;
    }

    int count = 0;
    DataNode* curr = list->head;

    while(curr->next != NULL){
        if(count == n){
            printf("%s", curr->data);
            return;
        }
        curr = curr->next;
        count += 1;
    }
    if(count == n){
        printf("%s", curr->data);
        return;
    }
    printf("Error\n");


}

// ถอด node ตัวแรกออกจาก list แล้วคืน node นั้นมา
DataNode* pop_front(SinglyLinklist* list){
    DataNode* node = list->head;
    list->head = node->next;
    node->next = NULL;
    list->count -= 1;
    return node;
}

// ถอด node ตัวสุดท้ายออกจาก list แล้วคืน node นั้นมา
DataNode* pop_back(SinglyLinklist* list){
    if(list->head->next == NULL){
        return pop_front(list);   // เหลือตัวเดียว
    }
    DataNode* prev = list->head;
    while(prev->next->next != NULL){
        prev = prev->next;
    }
    DataNode* node = prev->next;
    prev->next = NULL;
    list->count -= 1;
    return node;
}

// เอา node ที่มีอยู่แล้วไปต่อท้าย list (ไม่สร้าง node ใหม่)
void append_node(SinglyLinklist* list, DataNode* node){
    if(list->head == NULL){
        list->head = node;
    }else{
        DataNode* curr = list->head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = node;
    }
    list->count += 1;
}

// ท้าย 1 ตัว แล้วสลับ หน้า 2 / ท้าย 2 ไปเรื่อยๆ จนหมด
SinglyLinklist* taking_turns(SinglyLinklist* old){
    SinglyLinklist* res = createSignlyLinklist();
    if(old->head == NULL){
        return res;
    }

    append_node(res, pop_back(old));
    int from_front = 1;
    while(old->head != NULL){
        for(int i = 0; i < 2 && old->head != NULL; i++){
            if(from_front){
                append_node(res, pop_front(old));
            }else{
                append_node(res, pop_back(old));
            }
        }
        from_front = !from_front;
    }
    return res;
}

int main(){

    int num;
    char* data;
    data = (char*) malloc(sizeof(char)*101);

    SinglyLinklist* mylist = createSignlyLinklist();

    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        scanf(" %100s", data);
        insert_last(mylist, data);
    }

    SinglyLinklist* result = taking_turns(mylist);
    traverse(result);

    DataNode* curr = result->head;
    while(curr != NULL){
        free(curr->data);
        DataNode* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(result);
    free(mylist);
    free(data);

    return 0;

}