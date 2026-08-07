#include <stdio.h>

int main(){

    char text[101];
    int n;

    scanf("%[^\n]", text);
    scanf("%d", &n);

    text[n] = '\0';
    printf("%s", text);
}