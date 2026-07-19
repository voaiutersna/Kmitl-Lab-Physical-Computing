#include <stdio.h>

//Lab X-3: Type Conversion Report
int main(){

    int inp1;
    float inp2;
    char inp3;

    scanf("%d", &inp1);
    scanf("%f", &inp2);
    scanf(" %c", &inp3);

    printf("Int as Float: %.2f\n", (float) inp1);
    printf("Float as Int: %d\n", (int) inp2);
    printf("Char as ASCII: %d", (int) inp3);

    return 0;
}