#include <stdio.h>

int main(){

    char car1[51],car2[51];
    unsigned int day1[7],day2[7];
    unsigned int total1 = 0; 
    unsigned int total2 = 0;
    unsigned int totalequal = 0;
    unsigned int fastday1 = 0;
    unsigned int fastday2 = 0;
    double avg1,avg2;

    scanf("%50[^\n]", car1);
    for(unsigned int i = 0;i<7;i++){
        scanf(" %u", &day1[i]);
        total1 += day1[i];
    }
    scanf(" %50[^\n]", car2);
    for(unsigned int i = 0;i<7;i++){
        scanf(" %u", &day2[i]);
        total2 += day2[i];
    }

    for(unsigned int i = 0;i<7;i++){
        if(day1[i]==day2[i]){
            totalequal += 1;
            continue;
        }
        if(day1[i]<day2[i]){
            fastday1 += 1;
        }else{
            fastday2 += 1;
        }
    }

    printf("%s: %u minutes, average %d minutes/day\n",car1, total1, total1/7);
    printf("%s: %u minutes, average %d minutes/day\n",car2, total2, total2/7);
    printf("Faster days - %s: %u, %s: %u, Equal: %u",car1,fastday1,car2,fastday2,totalequal);


    return 0;
}