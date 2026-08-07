#include <stdio.h>
#include <stdbool.h>

int main(){

    char text[301];
    int num[301];
    char n;
    int sum = 0;

    scanf("%[^\n]", text);
    scanf(" %c", &n);
    
    bool issmall = true;
    if(n>=65 && n<=90){
        issmall = false;
    }
    
    int i = 0;
    while(1){
        if(text[i] == '\0'){
            break;
        }
        if(text[i] == n){
            num[sum] = i+1;
            sum += 1;
        }else if((text[i]>=65 && text[i]<=90)&&issmall){
            if(text[i]+32 == n){
                num[sum] = i+1;
                sum += 1;
            }
        }else if((text[i]>=97 && text[i]<= 122)&&(!issmall)){
            if(text[i]-32 == n){
                num[sum] = i+1;
                sum += 1;
            }
        }
        i++;
    }
    // printf("%d", sum);
    if(sum == 0){
        printf("Not found.");
    }else{
        printf("There is/are %d \"%c\" in the above sentences.\n", sum,n);
        printf("Position:");
        for(int i = 0;i<sum;i++){
            if(i==sum-1){
                printf(" %d",num[i]);
                continue;
            }
            printf(" %d,",num[i]);
        }
    }
    return 0;

}