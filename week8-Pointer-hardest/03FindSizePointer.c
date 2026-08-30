#include <stdio.h>
#include <stdlib.h>

int main(){

    char *str;
    str = (char*) malloc(sizeof(char)*101);
    scanf("%[^\n]", str);

    char *ptr = str;
    int i = 0;
    while (*(ptr+i)!= '\0'){
        i++;
    }
    printf("%d", i);

    return 0;
}