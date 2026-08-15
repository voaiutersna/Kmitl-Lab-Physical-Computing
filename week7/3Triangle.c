#include <stdio.h>
#include <math.h>

double perimeter(double a, double b){
    return sqrt(a*a + b*b);
}

double area(double a, double b){
    return ((double)1/2) * a * b;
}

int main(){

    double a, b;
    scanf("%lf", &a);
    scanf("%lf", &b);

    printf("Perimeter: %.2lf\n", perimeter(a,b) + a +b);
    printf("Area: %.2lf", area(a,b));
    
}

