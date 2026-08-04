#include <stdio.h>

int main(){

    int inp1,inp3,inp4;
    float inp2;
    int total = 0;

    scanf("%d", &inp1);
    scanf("%f", &inp2);
    scanf("%d", &inp3);
    scanf("%d", &inp4);

    if(inp1 == 0){
        total += 1;
    }
    if(inp2 >= 1){
        total += 1;
    }if(inp3 <= 2){
        total += 1;
    }if(inp3 - inp4 < 2){
        total += 1;
    }
    if(total == 0){
    printf("DRS allowed");
    }else{
    printf("DRS not allowed %d", total);

    }
    return 0;
}