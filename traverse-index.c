#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct DataNode{
    char* data;
    struct DataNode* next;
}DataNode;

typedef struct SinglyLinklist{
    unsigned int count;
    struct DataNode* head;
}SinglyLinklist;

DataNode* createDatanode(char* data){
    
    DataNode* node = (DataNode*) malloc(sizeof(DataNode));
    
    node->data = (char*) malloc(sizeof(char)* (strlen(data)+1));
    node->next = NULL;

    strcpy(node->data,data);

    return node;

}

SinglyLinklist* createSignlyLinklist(){

    SinglyLinklist* list = (SinglyLinklist*) malloc(sizeof(SinglyLinklist));
    list->count = 0;
    list->head = NULL;

    return list;
}

void insert_last(SinglyLinklist* list,char* data){
    
    DataNode* node = createDatanode(data);

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

void traverse_index(SinglyLinklist* list,int index){
    
    if(index < 0){
        index += (int)list->count;
    }

    if(index<0 || list->head == NULL || index >= (int) list->count){
        printf("Error\n");
        return;
    }

    int count = 0;
    DataNode* curr = list->head;

    while(curr->next!=NULL){
        if(count == index){
            printf("%s\n", curr->data);
            return;
        }
        count += 1;
        curr = curr->next;
    }

    if(count==index){
        printf("%s\n", curr->data);
            return;
    }
    
    printf("Error\n");
}




int main(){

    char* data;
    data = (char*) malloc(sizeof(char)*101);

    int index;

    SinglyLinklist* mylist = createSignlyLinklist();
    
    while(1){
        scanf(" %s", data);

        if(!strcmp(data,"Last")){
            scanf(" %d", &index);
            traverse_index(mylist,index);
            break;
        }

        insert_last(mylist,data);
    }
    
}