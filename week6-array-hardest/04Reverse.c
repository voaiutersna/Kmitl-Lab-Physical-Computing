#include <stdio.h>

int main(){

    char text[101];
    int l = 0;
    int r = 0;

    scanf("%[^\n]", text);
    int i = 0;
    while(1){
        if(text[i] == '\0'){
            break;
        }
        r += 1;
        i++;
    }
    r -= 1;
    // printf("%c", text[r]);
    char temp = ' ';
    while(l<=r){
        temp = text[r];
        text[r] = text[l];
        text[l] = temp;
        l+=1;
        r-=1;
    }
    printf("%s", text);
}