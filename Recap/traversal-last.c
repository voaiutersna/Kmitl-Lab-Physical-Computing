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



int main(){

    char data[101];
    int n;
    char condition;

    SinglyLinkedList* mylist = createSinglyLinkedList();

    scanf(" %d", &n);
    for(int i = 0;i<n;i++){
        scanf(" %c: %[^\n]", &condition, data);
        if(condition== 'F'){
            ;
        }else if(condition== 'L'){
            insert_last(mylist,data);
        }else if(condition == 'D'){
            ;
        }else{
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
