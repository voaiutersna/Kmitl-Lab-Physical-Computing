#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str;

    // Allocate memory for the string "Arnold Schwarzenegger" (including null terminator)
    str = (char *) malloc(sizeof(char)*101);
    scanf("%[^\n]", str);

    char *ptr = str;
    int count = 0;
    int i = 0;
    while (*(ptr+i) != '\0'){
        count += 1;
        i++;
    }

    // Free the allocated memory
    free(ptr);

    printf("%d", count);
    return 0;
}
