#include <stdio.h>
#include <ctype.h>
int main(){

    char inp;
    scanf("%c", &inp);

    if(inp>=65 && inp<=90){
        printf("uppercase");
    }else if(inp>=97 && inp<= 122){
        printf("lowercase");
    }else if(isalnum(inp)){
        printf("number");
    }else{
        printf("error");
    }
}