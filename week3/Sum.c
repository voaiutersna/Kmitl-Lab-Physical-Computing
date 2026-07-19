#include <stdio.h>

int main(){

    double n1,n2,n3,n4;
    
    scanf("%lf", &n1);
    scanf("%lf", &n2);
    scanf("%lf", &n3);
    scanf("%lf", &n4);

    printf("Summation is %.02lf\n",n1+n2+n3+n4);
    printf("Average is %.03lf",(n1+n2+n3+n4)/4);

    return 0;
}