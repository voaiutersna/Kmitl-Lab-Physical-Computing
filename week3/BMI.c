#include <stdio.h>
int main(){

    float n1,n2;
    
    scanf("%f", &n1);
    scanf("%f", &n2);

    printf("%f", n2/((n1/100)*(n1/100)));

    return 0;
}