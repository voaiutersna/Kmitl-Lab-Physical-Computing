#include <stdio.h>
#include <ctype.h>

int main(){

    double fuel_price;
    int choice[4];
    double acc[4];

    double EXPRESSWAY[1][2] = {0,0},ROMKLAO[1][2] = {0,0};
    scanf("%lf", &fuel_price);
    for(int i = 0; i<4;i++){
        scanf(" %d", &choice[i]);
    }
    for(int i = 0; i<4;i++){
        scanf(" %lf", &acc[i]);
        if(acc[i]==0){
            printf("Day %d: fuel %.2lf L, cost %.2lf Baht\n", i+1, 0.0, 0.0);
            continue;
        }
        double distance;
        double total = 0;
        if(choice[i]==1){
            distance = 29;
            total += ((distance/acc[i])*fuel_price)+60;
            EXPRESSWAY[0][0] += total;
            EXPRESSWAY[0][1] += 1;

        }else{
            distance = 25;
            total += ((distance/acc[i])*fuel_price);
            ROMKLAO[0][0] += total;
            ROMKLAO[0][1] += 1;
        }
        printf("Day %d: fuel %.2lf L, cost %.2lf Baht\n", i+1,distance/acc[i],total);
    }
    if(EXPRESSWAY[0][0]==0){
        printf("Expressway: 0.00 Baht\n");
    }else{
        printf("Expressway: %.2lf Baht\n",EXPRESSWAY[0][0]/EXPRESSWAY[0][1]);
    }
    // printf("%lf\n",EXPRESSWAY[0][0]);
    if(ROMKLAO[0][0]==0){
        printf("Romklao: 0.00 Baht");
    }else{
        printf("Romklao: %.2lf Baht",ROMKLAO[0][0]/ROMKLAO[0][1]);
    }
    // printf("Expressway: %.2lf Baht\n",EXPRESSWAY[0][0]/EXPRESSWAY[0][1]);
    // printf("Romklao: %.2lf Baht",ROMKLAO[0][0]/ROMKLAO[0][1]);

    return 0;
}