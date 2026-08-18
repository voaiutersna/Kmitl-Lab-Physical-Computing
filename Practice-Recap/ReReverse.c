#include <stdio.h>
#include <ctype.h>
int main(){

    char t[101];
    scanf("%[^\n]", t);
    // printf("%s", t);
    int i = 0;
    while(1){
        if(t[i] == '\0'){
            break;
        }
        i++;
    }
    int l = 0;
    int r = i-1;
    char temp = ' ';
    while(l<r){
        temp = t[l];
        t[l] = t[r];
        t[r] = temp;
        l+=1;
        r-=1;
    }
    printf("%s", t);

    return 0;
}