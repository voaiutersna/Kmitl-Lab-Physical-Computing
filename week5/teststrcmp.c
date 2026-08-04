#include <stdio.h>
#include <string.h>

int main(){

    if(!strcmp("skibidi","skibidi")){
        printf("Match");
    }else{
        printf("Not match");
    }

    // gonna error its compare address of pointer not the value
    // if("skibidi"=="skibidi"){
    //     printf("Match");
    // }else{
    //     printf("Not match");
    // }
}