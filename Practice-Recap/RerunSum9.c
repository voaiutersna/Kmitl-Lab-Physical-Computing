#include <stdio.h>

int main(){

    int total,i;
    while(1){
        scanf("%d", &i);
        if(i==-9){
            printf("%d", total);
            break;
        }
        total += i;
    }
}