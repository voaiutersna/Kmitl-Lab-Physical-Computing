#include <stdio.h>

int main(){

    double fuel_price;
    int choice[4];
    double acc[4];
    double Expresswayavg[2] = {0,0};
    double Romklaoavg[2] = {0,0};
    double liters = 0;
    double cost = 0;
    scanf("%lf", &fuel_price);
    for(int i = 0;i<4;i++){
        scanf(" %d", &choice[i]);
    }
    for(int i = 0;i<4;i++){
        scanf(" %lf", &acc[i]);
        if (acc[i]==0){
            printf("Day %d: fuel 0.00 L, cost 0.00 Baht\n", i+1);
            continue;
        }
        if(choice[i]==1){
            liters = 29/acc[i];
            cost = liters * fuel_price + 60;
            Expresswayavg[0] += 1;
            Expresswayavg[1] += cost;
        }else if(choice[i]==0){
            liters = 25/acc[i];
            cost = liters * fuel_price;
            Romklaoavg[0] += 1;
            Romklaoavg[1] += cost;
        }
        printf("Day %d: fuel %.2lf L, cost %.2lf Baht\n", i+1,liters,cost);
    }
    if(Expresswayavg[1] == 0){
        printf("Expressway: 0.00 Baht\n");
    }else{
        printf("Expressway: %.2lf Baht\n",Expresswayavg[1]/Expresswayavg[0]);
    }
    if(Romklaoavg[1] == 0){
        printf("Romklao: 0.00 Baht\n");
    }else{
        printf("Romklao: %.2lf Baht\n",Romklaoavg[1]/Romklaoavg[0]);
    }

    return 0;
}