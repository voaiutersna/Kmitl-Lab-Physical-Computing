#include <stdio.h>

//Lab X-4: Formatted Sensor Log
int main(){

    char name[13];
    float num;

    scanf("%s", name);
    scanf("%f", &num);

    printf("%-12s: %.1f",name,num);

    return 0;
}