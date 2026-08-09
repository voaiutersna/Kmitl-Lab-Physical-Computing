#include <stdio.h>

int main(){

    char car[100];
    scanf(" %[^\n]", car);
    int n;
    scanf(" %d", &n);
    int mile[n];
    for(int i = 0;i<n;i++){
        scanf(" %d", &mile[i]);
    }
    int speed;
    scanf(" %d", &speed);

    int result[1][2] = {0,0};
    int inserted = 0;
    for(int i = 0;i<n;i++){
        if(inserted != 0) break;
        if(speed<=mile[i]){
                if(i==0){
                    result[0][0] = mile[0];
                    result[0][1] = (n>1) ? mile[1] : 0;
                }else{
                    result[0][0] = mile[i-1];
                    result[0][1] = mile[i];
                }
                inserted += 2;
                break;
            }
    }

    printf("%s\n", car);
    if(inserted == 2){
        printf("%d - %d\n", result[0][0], result[0][1]);
    }else{
        printf("> %d\n", mile[n-1]);
    }

    return 0;
}