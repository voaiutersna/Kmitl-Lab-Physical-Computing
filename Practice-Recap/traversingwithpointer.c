#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str;

    // Allocate memory for the string "Arnold Schwarzenegger" (including null terminator)
    str = (char *) malloc(sizeof(char)*100);

    // Copy "Porsche Arnold" into the allocated memory
    strcpy(str, "Arnold Schwarzenegger");

    // Print the string
    char *ptr = str;
    int i = 0;
    while (*(ptr+i) != '\0'){
        printf("%c", *(ptr+i));
        i++;
    }

    // Free the allocated memory
    free(ptr);

    printf("\n");
    return 0;
}
