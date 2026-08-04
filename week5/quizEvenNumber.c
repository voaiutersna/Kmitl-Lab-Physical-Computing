#include <stdio.h>

int main(){
    
    int start,end;
    int sum = 0;
    scanf("%d %d", &start,&end);

    if(start>end){
        printf("pass :");
        for(int i = start;i>=end;i--){
            if(i%2==0){
                printf(" %d",i);
                sum += i;
            }
        }
        printf("\nSum : %d", sum);
    }else if(start<end){
        printf("pass :");
        for(int i = start;i<=end;i++){
            if(i%2==0){
                printf(" %d",i);
                sum += i;
                }
        }
        printf("\nSum : %d", sum);

    }else{
        printf("pass :");
        if(end%2==0){
            printf(" %d",end);
            sum += end;
        }
        printf("\nSum : %d", sum);
    }

    return 0;
}