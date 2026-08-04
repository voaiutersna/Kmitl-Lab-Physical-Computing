#include <stdio.h>

int main(){

    int inp;

    scanf("%d", &inp);

    if(inp>50){
        printf("Duck Type: Talkative Duck");
    }else if(inp>=11 && inp<=50){
        printf("Duck Type: Happy Duck");
    }else if(inp>=1 && inp<=10){
        printf("Duck Type: Chill Duck");
    }else if(inp==0){
        printf("Duck Type: Silent Duck");
    }else{
        printf("Error");
    }

    return 0;
}