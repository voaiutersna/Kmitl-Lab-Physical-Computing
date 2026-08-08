#include <stdio.h>
#include <stdbool.h>
int main(){
 
    char text[101];
    scanf("%s", text);
    
    //two pointer
    int l = 0;
    int r = 0;
    int c = 0;

    //finding length of text;
    while(1){
        if(text[c] == '\0'){
            break;
        }
        r += 1;
        c++;
    }

    r -= 1;
    int total_element = r;

    bool palindrome = true;
    
    while(l<=r){
        if(text[l]!=text[r]){
            printf("It is not Palindrome.");
            palindrome = false;
            break;
        }
        l+=1;
        r-=1;
    }
    if(palindrome){
        printf("It is Palindrome.");
    }
 
    return 0;
}