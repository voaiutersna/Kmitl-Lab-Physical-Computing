#include <stdio.h>

int main(){

    double a,b;

    scanf("%lf", &a);
    scanf("%lf", &b);

    printf("%.02lf", (double) a/b);

    return 0;
}