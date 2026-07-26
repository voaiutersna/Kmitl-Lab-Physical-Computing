#include <stdio.h>

int main(){

    double start, end, temp;
    
    scanf("%lf %lf", &start, &end);
    if (start > end){
        temp = end;
        end = start;
        start = temp;
    }
    double sacc=(1.5*1.5) / (2*(0.5));
    double tacc = (1.5)/(0.5);
    double stotal = 0;
    if (start == 1){
        stotal = 6 + ((end-start-1)*4);
    }else{
        stotal = (end-start)*4;
    }

    double sc = stotal - 2*sacc;
    double tc = sc / (1.5);

    double result = tacc + tacc + tc;
    printf("%.2lf", result);

    return 0;
}