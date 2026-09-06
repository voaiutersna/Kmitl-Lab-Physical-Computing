#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char *str;

    // Allocate memory for the string "Arnold Schwarzenegger" (including null terminator)
    str = (char *) malloc(sizeof(char)*101);
    scanf("%[^\n]", str);

    char *ptr = str;
    int i = 0;
    int l = 0;
    int u = 0;
    int d = 0;
    while(*(ptr+i)!='\0'){

        if(isupper(*(ptr+i))){
            u += 1;
        }else if(islower(*(ptr+i))){
            l += 1;
        }else if(isdigit(*(ptr+i))){
            d += 1;
        }
        i++;
    }


    // Free the allocated memory
    free(ptr);
    printf("Lowercase letters: %d\n", l);
    printf("Uppercase letters: %d\n",u);
    printf("Digits: %d",d);
    return 0;
}
