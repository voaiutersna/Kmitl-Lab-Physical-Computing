#include <stdio.h>

int main(){

    char car[100];
    double n1,n2,n3;
    
    scanf("%[^\n]", car);
    scanf("%lf", &n1);
    scanf("%lf", &n2);
    scanf("%lf", &n3);

    printf("%.4lf\n", n1);
    printf("%.4lf\n", n2);
    printf("%.2lf\n", n3);
    printf("%s", car);
    return 0;
}