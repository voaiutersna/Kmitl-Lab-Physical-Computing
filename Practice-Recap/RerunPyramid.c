#include <stdio.h>

int main(){

    int row;
    scanf("%d", &row);
    
    int central = row;
    int column = row*2-1;
    for(int r = 1;r<=row;r++){
        for(int c = 1;c<=column;c++){
            if(c==central || ((c>=central-r+1 ) && (c<= central+r-1))){
                printf("*");
                continue;
            }
            printf(" ");
        }
        printf("\n");
    }

}