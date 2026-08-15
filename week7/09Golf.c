#include <stdio.h>
#include <math.h>
double PI = 3.141592653589793;
double g = 9.81;
double degreeToRadius(double degree){
    return (degree * PI)/180;
}

int main(){
    double degree,u;
    scanf("%lf", &degree);
    scanf("%lf", &u);
    double sinx = pow(sin(degreeToRadius(degree)),2.0);
    double h = (pow(u,2.0)*sinx) / (2*g);

    printf("theta (degree) : %.0lf\n",degree);
    printf("u (m/s) : %.0lf\n", u);
    printf("h (m) : %.4lf\n", h);
    return 0;
}