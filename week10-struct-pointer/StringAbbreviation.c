#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_abbreviation(char* str){

    char* token = strtok(str, " ");
    while(token != NULL){
        printf("%c.", token[0]);   // ตัวแรกของแต่ละคำ ตามด้วย .
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main(){

    char* str = (char*) malloc(sizeof(char)*201);   // 200 ตัว + '\0'

    scanf("%200[^\n]", str);
    print_abbreviation(str);

    free(str);
    return 0;
}
