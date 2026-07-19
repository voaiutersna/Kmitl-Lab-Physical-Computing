#include <stdio.h>
#include <math.h>

int main(){
    double n1, n2;
    scanf("%lf",&n1);
    scanf("%lf",&n2);
    printf("%.02lf",sqrt(pow(n1, 2)+pow(n2, 2)));
    return 0;
}