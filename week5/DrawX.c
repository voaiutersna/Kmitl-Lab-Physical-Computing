#include <stdio.h>

int main(){

    int row,column;
    scanf("%d", &row);
    int n = row;
    column = row;

    for(int r = 1;r<=row;r++){
        for(int c = 1;c<=column;c++){
            
            if(c==r || c == n-r+1){
                printf("-");
                continue;
            }
            printf("#");
        }
        printf("\n");
    }

    return 0;
}