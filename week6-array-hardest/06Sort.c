#include <stdio.h>

int main(){

    int num[] = {6,5,4,3,2,1};
    int size = 6;
    int temp = 0;
    for(int i = 0;i<6;i++){
        for(int j = 0;j<size-i-1;j++){
            if(num[j]>num[j+1]){
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }

    for(int i = 0;i<size;i++){
        printf("%d ", num[i]);
    }

    return 0;
}