#include <stdio.h>
#include <stdlib.h>

int main(){

    char *str;
    str = (char*) malloc(sizeof(char)*101);
    scanf("%[^\n]", str);
    
    char *left = str;
    char *right = str;

    while (*right != '\0') {
        right++;
    }
    right--;
    
    while(left<right){
        char temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }

    printf("%s\n", str);
    free(str);

    return 0;
}