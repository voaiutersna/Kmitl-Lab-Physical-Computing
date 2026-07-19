#include <stdio.h>
#include <math.h>
int main(){

    double n1,n2,n3;
    
    scanf("%lf", &n1);
    scanf("%lf", &n2);
    scanf("%lf", &n3);

    double price = (n1*n3) - ((n1*(n2/100))*n3);

    printf("%.02lf\n", price);
    return 0;
}