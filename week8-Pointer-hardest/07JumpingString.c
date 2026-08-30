#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(){

    char *str;
    unsigned int num;
    int hop;
    scanf("%u", &num);
    scanf("%d", &hop);
    str = (char*) malloc(sizeof(char)*828721);
    scanf(" %[^\n]", str);

    char *ptr = str;
    int count = 0;
    int totalcount = 0;
    printf("%c", *ptr);

    while (*ptr != '\0') {
        if(count==hop){
            printf("%c", *ptr);
            count=0;
        }
        count += 1;
        totalcount += 1;
        ptr++;
    }


    return 0;
}