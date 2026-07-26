#include <stdio.h>

int main(){

    double number;

    scanf("%lf", &number);

    if(number >= 80 && number <= 100){
        printf("%s", "A");
    }else if(number >= 70 && number <= 79.99){
        printf("%s", "B");

    }else if(number >= 60 && number <= 69.99){
        printf("%s", "C");
        
    }else if(number >= 50 && number <= 59.99){
        printf("%s", "D");
        
    }else if(number >= 0 && number <= 49.99){
        printf("%s", "F");
    }else{
        printf("%s", "Out of Range");
    }

    return 0;
}