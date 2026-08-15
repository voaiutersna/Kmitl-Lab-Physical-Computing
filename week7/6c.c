#include <stdio.h>
#include <math.h>
int main(){

    double a,b;
    scanf("%lf %lf", &a,&b);

    printf("sqrt(%.0lf^2+%.0lf^2)=%.2lf", a,b,sqrt(pow(a,2.0)+pow(b,2.0)));
}