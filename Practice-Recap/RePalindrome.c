#include <stdio.h>
#include <stdbool.h>

int main(){
    char t[101];
    int l = 0;
    int r = 0;
    scanf(" %[^\n]", t);
    while(1){
        if(t[r]=='\0'){
            break;
        }
        r+=1;
    }

    // printf("%d", r);
    r -= 1;
    bool isvalid = true;
    while(l<r){
        if(t[l]!=t[r]){
            isvalid = false;
        }
        l+=1;
        r-=1;
    }
    if(isvalid){
        printf("It is Palindrome.");
    }else{
        printf("It is not Palindrome.");
    }


    return 0;
}