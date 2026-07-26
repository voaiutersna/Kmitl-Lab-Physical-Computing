#include <stdio.h>

int main(){

    double price,percent,amount;
    scanf("%lf",&price);
    scanf("%lf", &percent);
    scanf("%lf", &amount);

    double result1 = (price*amount)-(price*amount*(percent/100));
    double result2 = (price*amount)-(price*((int)amount/3));

    if(result1 <= result2){
        printf("Discount %.0lf%%\n", percent);
        printf("%.2lf", result1);
    }else{
        printf("Buy 2 Get 1\n");
        printf("%.2lf", result2);
    }

    return 0;
}