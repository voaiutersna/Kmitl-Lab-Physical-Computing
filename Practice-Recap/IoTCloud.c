#include <stdio.h>

int main(){

    double monthprice;
    int percent,amount;

    scanf("%lf", &monthprice);
    scanf("%d", &percent);
    scanf("%d", &amount);

    printf("Total: %.02lf", ((monthprice*amount)-(monthprice*amount*((double)percent/100))));

    return 0;
}