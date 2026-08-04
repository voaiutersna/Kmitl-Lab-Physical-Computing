#include <stdio.h>
#include <ctype.h>

int main(){

    char c;
    scanf("%c", &c);

    if(islower(c)){
        c = toupper(c);
        printf("%c", c);
    }else if(isupper(c)){
        c = tolower(c);
        printf("%c", c);
    }else{
        printf("error");
    }
}
