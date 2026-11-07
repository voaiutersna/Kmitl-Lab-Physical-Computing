#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct DataNode{
    char* data;
    struct DataNode* next;
};


typedef struct LinkList{
    unsigned int count;
    struct DataNode* head;
};

struct DataNode* createDatanode(char* data){
    struct DataNode* p = (struct DataNode*)malloc(sizeof(struct DataNode));    
    (*p).data = (char*) malloc(strlen(data)+1);
    strcpy((*p).data,data);
    (*p).next = NULL;

    return p;
}

void traverse(struct LinkList* list){

    if((*list).head == NULL){
        printf("%s\n", "This is an empty link list");
        return;
    }

    struct DataNode* curr = (*list).head;
    while(curr != NULL){
        printf("%s", (*curr).data);
        if((*curr).next != NULL){
            printf(" -> ");
        }
        curr = (*curr).next;

    }

    printf("\n");

    return;
}

void insertLast(struct LinkList* list,char* data){
    //create Data node first
    struct DataNode* p = createDatanode(data);

    //when its null
    if((*list).head == NULL){
        (*list).head = p;
    }else{
        struct DataNode* curr = (*list).head;
        
        while ((*curr).next != NULL){
            curr = (*curr).next;
        }
        
        (*curr).next = p;
    }
    (*list).count += 1;

}


int main(){

    struct LinkList* mylist =  (struct LinkList*) malloc(sizeof(struct LinkList));
    (*mylist).count = 0;
    (*mylist).head = NULL;

    traverse(mylist);                            // This is an empty list.
    insertLast(mylist, "A");
    insertLast(mylist, "B");
    insertLast(mylist, "C");
    traverse(mylist);                            // A -> B -> C

}