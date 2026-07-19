#include <stdio.h>

int main(){

    // int num1,num2,num3,num4,num5;
    // scanf("%1d%1d%1d%1d%1d", &num1,&num2,&num3,&num4,&num5);
    // printf("%d%d%d%d%d", num3,num4,num5,num1,num2);

    int number;
    scanf("%d", &number);
    printf("%d",(number / 100) % 10);
    printf("%d",(number / 10) % 10 );
    printf("%d",number % 10);
    printf("%d",(number / 10000) % 10);
    printf("%d",(number / 1000) % 10);

    return 0;
}