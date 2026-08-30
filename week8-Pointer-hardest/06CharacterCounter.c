#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(){

    char *str;
    int l=0,u=0,d=0;
    str = (char*) malloc(sizeof(char)*101);
    scanf("%[^\n]", str);

    char *ptr = str;

    while (*ptr != '\0') {

        if(isdigit(*ptr)){
            d++;
        }else if(isupper(*ptr)){
            u++;
        }else if(islower(*ptr)){
            l++;
        }
        ptr++;
    }

    printf("Lowercase letters: %d\n", l);
    printf("Uppercase letters: %d\n", u);
    printf("Digits: %d", d);

    return 0;
}