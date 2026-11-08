#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DataNode{
    char* data;
    struct DataNode* next;
}DataNode;

typedef struct SinglyLinkedList{
    unsigned int count;
    struct DataNode* head;
}SinglyLinkedList;

DataNode* createDataNode(char* data){
    DataNode* new_node = (DataNode*) malloc(sizeof(DataNode));
    new_node->data = (char*) malloc(strlen(data)+1);

    strcpy(new_node->data,data);
    new_node->next = NULL;

    return new_node;
}

SinglyLinkedList* createSinglyLinkedList(){
    SinglyLinkedList* list = (SinglyLinkedList*) malloc(sizeof(SinglyLinkedList));
    list->count = 0;
    list->head = NULL;
    return list;
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
    
    DataNode* node = createDataNode(data);
    
    if(list->head == NULL){
        list->head = node;
    }else{
        DataNode* curr = list->head;
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = node;
    }
    list->count += 1;
}

void insert_front(SinglyLinkedList* list, char* data) {
    
    DataNode* node = createDataNode(data);
    if(list->head == NULL){
        list->head = node;
        list->count+=1;
        return;
    }

    DataNode* prev_node = list->head;
    list->head = node;
    node->next = prev_node;
    list->count += 1;
}

void delete(struct SinglyLinkedList* list, char* data) {
    
    DataNode* curr = list->head;

    if(list->head == NULL || (list->count == 1 && strcmp(list->head->data,data))){
        printf("Cannot delete, %s does not exist.\n", data);
        return;
    }

    //Delete Head
    if(!strcmp(list->head->data,data)){
        list->head = list->head->next;
        list->count -= 1;
        return;
    }
    //Delete Middle
    while(curr->next->next != NULL){
        if(!strcmp(curr->next->data,data)){
            curr->next = curr->next->next;
            list->count -= 1;
            return;
        }
        curr = curr->next;
    }

    //Delete Last
    if(!strcmp(curr->next->data,data)){
        curr->next = NULL;
        list->count -= 1;
    return;
    }

    //Not Exist
    printf("Cannot delete, %s does not exist.\n", data);
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