#include <stdio.h>

int main(){

    int total = 0;
    int n;

    do{
        scanf("%d", &n);
        if (n==-9){
            printf("%d", total);
            break;
        }
        total += n;
    }while(n!=-9);
    
    return 0;
    
}