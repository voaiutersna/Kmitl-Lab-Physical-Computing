#include <stdio.h>

int main(){
    double a,b,c;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    if(a+b>c && b+c > a && a+c >b){
        printf("Triangle is valid.");
    }else{
        printf("Triangle is not valid.");
    }
}