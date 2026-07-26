#include <stdio.h>

int main(){

    double number;

    scanf("%lf", &number);

    if(number >= 0 && number <= 5.032){
        printf("%s", "Bangkok");
    }else if(number >= 5.032 && number <= 35.477){
        printf("%s", "Samut Prakarn");

    }else if(number >= 35.477 && number <= 52.900){
        printf("%s", "Chachoengsao");
        
    }else if(number >= 52.900 && number <= 58.855){
        printf("%s", "Chon Buri");
    }else{
        printf("%s", "InValid");
    }

    return 0;
}