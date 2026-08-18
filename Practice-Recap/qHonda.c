#include <stdio.h>

int main(){

    char text[101];
    int n;
    scanf(" %[^\n]",text);
    scanf("%d", &n);
    int speed[n];
    int curr;
    for(int i = 0;i<n;i++){
        scanf(" %d", &speed[i]);
    }
    scanf(" %d", &curr);
    // for(int i = 0;i<n;i++){
    //     printf(" %d", speed[i]);
    // }
    printf("%s\n", text);

    int result[2] = {0,0};
    for(int i = 0;i<n;i++){
        
        if(i==0 && curr == speed[i]){
            result[0] = speed[i];
            result[1] = speed[i+1];
            // printf("IN1\n");
            break;
        }
        if(i==n-1 && curr>speed[i]){
            result[0] = speed[i];
            // printf("IN2\n");
            break;
        }
        if(i!=0 && speed[i] == curr){
            result[0] = speed[i-1];
            result[1] = speed[i];
            // printf("IN3\n");
            break;
        }
        if(i!=0 && curr < speed[i]){
            result[0] = speed[i-1];
            result[1] = speed[i];
            // printf("IN4\n");
            break;
        }
    }

    if(result[1] != 0){
        printf("%d - %d\n", result[0],result[1]);
    }else{
        printf("> %d",result[0]);
    }
    


    return 0;
}