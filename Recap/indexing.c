#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DataNode {
    char* data;
    struct DataNode* next;
}DataNode;

typedef struct SinglyLinkedList {
    unsigned int count;
    struct DataNode* head;
}SinglyLinkedList;

DataNode* createDataNode(char* data){

    //create DataNode
    DataNode* node = (DataNode*) malloc(sizeof(DataNode));
    
    //data is string so malloc for storage of string
    node->data = (char*) malloc(sizeof(char)*(strlen(data)+1));
    node->next = NULL;

    //acopy data to inside storage heap of data node
    strcpy(node->data,data);

    return node;

}

SinglyLinkedList* createSinglyLinkedList(){
    
    //create SinglyLinklist
    SinglyLinkedList* mylist = (SinglyLinkedList*) malloc (sizeof(SinglyLinkedList));
    mylist->count = 0;
    mylist->head = NULL;

    return mylist;
}

void traverse(SinglyLinkedList *list){
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
void insert_last(SinglyLinkedList *list, char *data){
    
    //create Data Node
    DataNode* new_node = createDataNode(data);
    
    //condition 1 : link list is null
    if(list->head == NULL){
        list->head = new_node;
        list->count += 1;
        return;
    }

    //Loop until last node of link list
    DataNode* curr = list->head;
    while(curr->next != NULL){
        // printf("Getting in loop");
        curr = curr->next;
    }
    curr->next = new_node;
    list->count += 1;
    
}

void insert_front(SinglyLinkedList* list, char* data){

    //create Data Node
    DataNode* new_node = createDataNode(data);
    if(list->head == NULL){
        list->head = new_node;
        list->count += 1;
        return;
    }else{
        DataNode* prev_head = list->head;
        list->head = new_node;
        new_node->next = prev_head;
        list->count += 1;
    }

    //optimize
    // new_node->next = list->head;
    // list->head = new_node;
    // list->count += 1;
}

void delete(struct SinglyLinkedList* list, char* data) {

    if(list->count == 0){
        printf("Cannot delete, %s does not exist.\n",data);
        return;
    }

    DataNode* curr = list->head;

    //Condition Delete Head node;
    if(!strcmp(list->head->data,data)){
        list->head = list->head->next;
        list->count -= 1;
        return;
    }

    //Condition Delete Middle node;
    while(curr->next != NULL){
        if(!strcmp(curr->next->data,data)){
            curr->next = curr->next->next;
            list->count -= 1;
            return;
        }
        curr = curr->next;
    }
    printf("Cannot delete, %s does not exist.\n",data);

    return;
}

void traverse_indexing(struct SinglyLinkedList* list,int index){

    
    if(index < 0){
        index += (int)list->count;
        // printf("Get in: %d", index);
    }
    
    if((int)list->count <= index || (int)list->count == 0 || index < 0){
        printf("Error\n");
        return;
    }

    int count = 0;
    DataNode* curr = list->head;
    while(curr->next != NULL){
        if(count == index){
            printf("%s\n", curr->data);
            return;
        }
        count += 1;
        curr = curr->next;
    }

    if(count==index){
        printf("%s\n", curr->data);
    }

    return;
}


int main(){

    int index;
    char* data  = (char*) malloc(sizeof(char)*21);
    SinglyLinkedList* mylist = createSinglyLinkedList();

    while(1){
        scanf(" %s",data);
        if(!strcmp(data,"Last")){
            scanf(" %d", &index);
            traverse_indexing(mylist,index);
            break;
        }
        insert_last(mylist,data);
    }




    // traverse(mylist);
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
