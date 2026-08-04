#include <stdio.h>

int main(){

    int age,day;
    int total = 0;
    scanf("%d", &age);
    scanf("%d", &day);
    if(day==4){
        printf("Ticket price: 100 Baht");
    }else{
        if(age <= 12){
            total = 120;
        }else if(age >=13 && age <=59){
            total = 220;
        }else if(age >= 60){
            total = 140;
        }
        if(day == 1 || day == 7){
            total += 20;
        }
        printf("Ticket price: %d Baht",total);
    }

    return 0;
}