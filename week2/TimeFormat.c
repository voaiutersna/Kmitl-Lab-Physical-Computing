#include <stdio.h>

int main(){
    
    int hour,min;

    scanf("%d", &hour);
    scanf("%d", &min);

    printf("%02d:%02d", hour, min);

    return 0;
}