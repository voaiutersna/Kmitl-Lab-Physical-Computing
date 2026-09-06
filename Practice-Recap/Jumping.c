#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str;
    int size;
    int f;
    scanf("%d", &size);
    scanf("%d", &f);
    // Allocate memory for the string "Arnold Schwarzenegger" (including null terminator)
    str = (char *) malloc(sizeof(char)*828721);
    scanf(" %[^\n]", str);

    char *ptr = str;
    printf("%c", *(ptr));

    int count = 1;
    int i = 1;
    while(*(ptr+i)!='\0'){

        if(count == f){
            count = 1;
            printf("%c", *(ptr+i));
            i++;
            continue;
        }

        count += 1;
        i++;
    }


    // Free the allocated memory
    free(ptr);
    return 0;
}
