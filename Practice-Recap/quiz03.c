#include <stdio.h>

int main(){

    float inp1;
    float inp2;
    char inp3;

    scanf("%f", &inp1);
    scanf("%f", &inp2);
    scanf(" %c", &inp3);
    
    printf("%010.3f\n", (float)inp1);
    printf("%d\n", (int) inp2);
    printf("%d", inp3);

    return 0;
}