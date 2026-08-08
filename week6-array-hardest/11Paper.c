#include <stdio.h>

int main(){

    int a,b;
    char c,d;

    scanf("%c%d", &c,&a);
    scanf(" %c%d", &d,&b);
    // printf("%d", a);
    // printf("%d", b);

    int until = b-a;
    int result = 1;
    for(int i = 1;i<=until;i++){
        result *= 2;
    }
    printf("%d", result);

    return 0;
}