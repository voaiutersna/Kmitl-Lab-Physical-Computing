#include <stdio.h>

int main(){

    double Age,Height,Weight,avga,avgh,avgw;
    double totala = 0,totalh = 0,totalw = 0;
    int n1 = 0,n2 = 0,n3 = 0,n4 = 0;

    for (int i = 1; i<=50; i++){

        scanf("%lf %lf %lf", &Age,&Height,&Weight);
        totala += Age;
        totalh += Height;
        totalw += Weight;
        if(Age >= 20 && Height >= 160){
            n1 += 1;
        }
        if(Age < 20 && (Height <= 180 || Weight >= 60)){
            n2 += 1;
        }
        if(Age >= 30 && Weight >= 40 && Weight <= 80){
            n3 += 1;
        }
        if(Age < 40 &&(Weight < 85 || Height <= 200)){
            n4 += 1;
        }
    }

    avga = totala / 50;
    avgh = totalh / 50;
    avgw = totalw / 50;

    printf("Age >= 20 and Height >= 160: %d\n",n1);
    printf("Age < 20 and Height <= 180 or Weight >= 60: %d\n",n2);
    printf("Age >= 30 and Weight >= 40 and Weight <= 80: %d\n",n3);
    printf("Age < 40 and Weight < 85 or Height <= 200: %d\n",n4);
    printf("Average Age: %.0lf\n", avga);
    printf("Average Height: %.2lf\n",avgh);
    printf("Average Weight: %.2lf\n",avgw);
    return 0;
}