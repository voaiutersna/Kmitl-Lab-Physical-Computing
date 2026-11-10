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

int main(){
    
    int num;
    char condition;
    char* data;
    data = (char*) malloc(sizeof(char)*101);

    SinglyLinklist* mylist = createSignlyLinklist();
    
    while(1){
        scanf(" %s", data);
        if(!strcmp(data,"Last")){
            scanf(" %d", &num);
            traverse_index(mylist,num);
            break;
        }
        insert_last(mylist,data);
    }

    // DataNode* curr = mylist->head;
    // while(curr != NULL){
    //     free(curr->data);
    //     DataNode* temp = curr;
    //     curr = curr->next;
    //     free(temp);
    // }

    // free(mylist);

    return 0;

}