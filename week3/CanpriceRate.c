#include <stdio.h>
#include <math.h>
int main(){

    double n1,n2,n3,v;
    
    scanf("%lf", &n1);
    scanf("%lf", &n2);
    scanf("%lf", &n3);
    v = n3 * 3.14159265359 * (pow((n2/2),2));

    printf("Volume : %.02lfml\n",v);
    printf("Baht/ml : %.04lf",n1/v);

    return 0;
}