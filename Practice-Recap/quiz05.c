#include <stdio.h>

int main(){

    char text[201];
    scanf("%[^\n]",text);
    printf("Hello, %s!",text);

    return 0;
}