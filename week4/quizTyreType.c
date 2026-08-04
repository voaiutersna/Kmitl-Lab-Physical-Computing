#include <stdio.h>

int main(){

    char c;
    scanf("%c", &c);

    if(c=='s' || c=='S'){
        printf("Soft");
    }
    if(c=='m'||c=='M'){
        printf("Medium");
    }
    if(c=='h'||c=='H'){
        printf("Hard");
    }
    if(c=='i'||c=='I'){
        printf("Intermediate");
    }
    if(c=='w'||c=='W'){
        printf("Wet");
    }

    return 0;
}