#include <stdio.h>
#include <stdbool.h>

int main(){

    int n[] = {40,50,10,20,30};
    int size = 5;
    int temp = 0;

    for(int i = 0;i<size;i++){
        bool issorted = true;        
        for(int j = 0;j<size-i-1;j++){
            if(n[j] > n[j+1]){
                issorted = false;
                temp = n[j];
                n[j] = n[j+1];
                n[j+1] = temp;
            } 
        }
        if(issorted == true){
            break;
        }
    }

    for(int i = 0;i<size;i++){
        printf("%d ", n[i]);
    }

    return 0;
}