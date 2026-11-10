#include <string.h>
#include <stdio.h>
#include <stdlib.h>



struct DataNode {
    char* data;
    struct DataNode* next;
};

struct SinglyLinklist {
    unsigned int count;
    struct DataNode* head;
};

struct DataNode* createDataNode(char* data){
    
    struct DataNode* node = (struct DataNode*) malloc(sizeof(struct DataNode));
    node->data = malloc(sizeof(char)*(strlen(data)+1));
    node->next = NULL;

    strcpy(node->data,data);
    return node;
}

struct SinglyLinklist* createSignlyLinklist(){
    
    struct SinglyLinklist* list = (struct SinglyLinklist*) malloc(sizeof(struct SinglyLinklist));
    
    //default
    list->count = 0;
    list->head = NULL;

    return list;
}

void insert_last(struct SinglyLinklist* list,char* data){

    struct DataNode* node = createDataNode(data);

    if(list->head == NULL){
        list->head = node;
        list->count += 1;
    }else{
        struct DataNode* curr = list->head;
        
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = node;
        list->count += 1;
    }

}

void insert_front(struct SinglyLinklist* list, char* data){
    
    struct DataNode* node = createDataNode(data);
    
    //head is null
    if(list->head == NULL){
        list->head = node;
        list->count += 1;
        return;
    }else{
        struct DataNode* prev_head = list->head;
        list->head = node;
        node->next = prev_head;
        list->count += 1;
        return;
    }
}

void delete(struct SinglyLinklist* list, char* data){
    
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


    struct DataNode* prev = list->head;
    struct DataNode* curr = list->head->next;

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

void traverse(struct SinglyLinklist* list){

    if(list->head == NULL){
        printf("This is an empty list.\n");
        return;
    }

    struct DataNode* curr = list->head;

    while(curr->next != NULL){
        printf("%s", curr->data);
        printf(" -> ");
        curr = curr->next;
    }
    printf("%s\n", curr->data);

}

void traverse_index(struct SinglyLinklist* list, int n){

    if(n<0){
        n += (int) list->count;
    }
    if(n<0 || n>= (int)list->count || list->head == NULL){
        printf("Error\n");
        return;
    }

    int count = 0;
    struct DataNode* curr = list->head;

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

    struct SinglyLinklist* mylist = createSignlyLinklist();
    
    while(1){
        scanf(" %s", data);
        if(!strcmp(data,"Last")){
            scanf(" %d", &num);
            traverse_index(mylist,num);
            break;
        }
        insert_last(mylist,data);
    }

    // struct DataNode* curr = mylist->head;
    // while(curr != NULL){
    //     free(curr->data);
    //     struct DataNode* temp = curr;
    //     curr = curr->next;
    //     free(temp);
    // }

    // free(mylist);

    return 0;

}