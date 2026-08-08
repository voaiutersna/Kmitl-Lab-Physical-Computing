#include <stdio.h>

int main(){

    char car[2][51];
    int day[2][51];
    int faster[2] = {0,0};
    int count[2] = {0,0};
    int totalequal = 0;
    for(int i = 0;i<2;i++){
        scanf(" %[^\n]", car[i]);
        for(int j = 0;j<7;j++){
            scanf(" %d", &day[i][j]);
            count[i] += day[i][j];
        }
    }

    for(int i = 0;i<7;i++){
        if(day[0][i]==day[1][i]){
            totalequal += 1;
            continue;
        }
        if(day[0][i]<day[1][i]){
            faster[0] += 1;
        }else{
            faster[1] += 1;
        }
    }

    printf("%s: %d minutes, average %d minutes/day\n", car[0], count[0], count[0]/7);
    printf("%s: %d minutes, average %d minutes/day\n", car[1], count[1], count[1]/7);
    printf("Faster days - %s: %d, %s: %d, Equal: %d", car[0],faster[0],car[1],faster[1],totalequal);




}