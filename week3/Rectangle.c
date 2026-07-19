#include <stdio.h>

int main(){

    double n1,n2;
    
    scanf("%lf", &n1);
    scanf("%lf", &n2);

    printf("Perimeter of rectangle = %.04lf units\n",2*(n1+n2));

    return 0;
}