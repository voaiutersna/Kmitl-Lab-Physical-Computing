#include <stdio.h>

int main(){

    int inp1;
    float inp2;
    char inp3;
    char inp4[21];

    scanf("%d", &inp1);
    scanf("%f", &inp2);
    scanf(" %c", &inp3);
    scanf("%s", inp4);

    printf("Integer: %d\n", inp1);
    printf("Float: %.3f\n", inp2);
    printf("Character: %c\n", inp3);
    printf("String: %s\n", inp4);

    return 0;
}