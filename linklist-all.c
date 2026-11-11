#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct DataNode{
    char* data;
    struct DataNode* next;
}DataNode;

typedef struct Signlylinklist{
    unsigned int count;
    struct DataNode* head;
}Signlylinklist;

DataNode* createDatanode(char* data){

    DataNode* node = (DataNode*) malloc(sizeof(DataNode));
    node->data = (char*) malloc(sizeof(char)*(strlen(data)+1));
    node->next = NULL;

    strcpy(node->data,data);

    return node;
}

Signlylinklist* createSignlylist(){

    Signlylinklist* list = (Signlylinklist*) malloc(sizeof(Signlylinklist));
    list->count = 0;
    list->head = NULL;

    return list;
}

void insert_last(Signlylinklist* list,char* data){
    DataNode* node = createDatanode(data);

    if(list->head==NULL){
        list->head = node;
        list->count += 1;
        return;
    }

    DataNode* curr = list->head;

    while(curr->next != NULL){
        curr = curr->next;
    }

    curr->next = node;
    list->count += 1;
}

void insert_front(Signlylinklist* list,char* data){
    DataNode* node = createDatanode(data);
    
    if(list->head == NULL){
        list->head = node;
        list->count += 1;
        return;
    }

    DataNode* prev_head = list->head;
    list->head = node;
    node->next = prev_head;
    list->count += 1;
}

void traverse(Signlylinklist* list){


    if(list->head == NULL){
        printf("This is an empty list.\n");
        return;
    }

    DataNode* curr = list->head;

    while(curr->next != NULL){
        printf("%s -> ", curr->data);
        curr = curr->next;
    }
    printf("%s", curr->data);
    
}

void delete(Signlylinklist* list,char* data){

    if(list->head == NULL || ( strcmp(list->head->data,data) && list->count == 0)){
        printf("Cannot delete, %s does not exist.\n",data);
        return;
    }

    if(!strcmp(list->head->data,data)){
        list->head = list->head->next;
        list->count -= 1;
        return;
    }

    DataNode* curr = list->head;

    while(curr->next != NULL){
        if(!strcmp(curr->next->data,data)){
            curr->next = curr->next->next;
            list->count -= 1;
            return;
        }
        curr = curr->next;
    }
    
    printf("Cannot delete, %s does not exist.\n",data);
    
}

int main(){
    
    char* data;
    char condition;
    unsigned int n;
    
    data = (char*) malloc(sizeof(char)*101);

    Signlylinklist* mylist = createSignlylist();
    
    scanf(" %u", &n);
    for(int i = 0;i<n;i++){
        scanf(" %c: %[^\n]", &condition,data);
        if(condition == 'F'){
            insert_front(mylist,data);
        }else if(condition == 'L'){
            insert_last(mylist,data);
        }else if(condition == 'D'){
            delete(mylist,data);
        }else{
            printf("Invalid Condition!\n");
        }
    }

    traverse(mylist);

    return 0;
}