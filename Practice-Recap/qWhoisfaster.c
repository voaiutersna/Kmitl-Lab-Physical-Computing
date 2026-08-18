#include <stdio.h>

int main(){

    char car1[50];
    char car2[50];
    int time1[7];
    int time2[7];
    int total1 = 0;
    int total2 = 0;
    int faster[] = {0,0,0};

    scanf("%[^\n]", car1);
    for(int i = 0;i<7;i++){
        scanf(" %d", &time1[i]);
        total1 += time1[i];
    }
    scanf(" %[^\n]", car2);
    for(int i = 0;i<7;i++){
        scanf(" %d", &time2[i]);
        total2 += time2[i];
    }

    printf("%s: %d minutes, average %d minutes/day\n", car1,total1,total1/7);
    printf("%s: %d minutes, average %d minutes/day\n", car2,total2,total2/7);

    for(int i = 0;i<7;i++){
        if(time1[i]<time2[i]){
            faster[0] += 1;
        }else if(time1[i]>time2[i]){
            faster[1] += 1;
        }else{
            faster[2] += 1;
        }
    }
    printf("Faster days - %s: %d, %s: %d, Equal: %d\n",car1,faster[0],car2,faster[1],faster[2]);

    
    
}