#include <stdio.h>

int main(){

    unsigned int num[5],n;

    scanf("%u %u %u %u %u",&num[0],&num[1],&num[2],&num[3],&num[4]);
    scanf("%u", &n);

    printf("Value at index %u is %u",n, num[n]);

    return 0;
}