#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Book {
    char id[10];
    char name[100];
    char author[100];
} Book;

int main(){

    int n;
    char target[10];

    scanf("%d", &n);
    scanf(" %9s", target);

    Book* books = (Book*) malloc(sizeof(Book) * n);

    for(int i = 0; i < n; i++){
        scanf(" %9s %99s %99s", books[i].id, books[i].name, books[i].author);
    }

    int found = 0;
    for(int i = 0; i < n; i++){
        if(strcmp(books[i].id, target) == 0){
            printf("%s %s %s\n", books[i].id, books[i].name, books[i].author);
            found = 1;
            break;
        }
    }

    if(!found){
        printf("Not Found\n");
    }

    free(books);
    return 0;
}
