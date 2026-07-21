#include <stdio.h>

int main(){
    
    // long double num;
    // scanf("%LF", &num);
    // printf("%.02LF", num);

    unsigned long long num;
    int num2;
    long long int_big;

    scanf("%llu", &num);
    scanf("%d", &num2);
    scanf("%lld", &int_big);
    
    printf("unsigned long long: %llu\n", num);
    printf("int: %d\n", num2);
    printf("long long: %lld", int_big);
}