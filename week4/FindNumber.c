#include <stdio.h>
#include <math.h>
int main(){

    float num1,num2, num3;

    scanf("%f %f %f", &num1, &num2, &num3);

    if((num1 <= num2 || num1 <= num3) && (num1 >= num3 || num1 >= num2)){
        printf("%.2f", num1);
    }else if((num2 <= num3 || num2 <= num1) && (num2 >= num1 || num2 >= num3)){
        printf("%.2f", num2);
    }else{
        printf("%.2f", num3);        
    }

    return 0;
}