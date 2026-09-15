#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(){

    struct count {
        unsigned int character;
        unsigned int word;
        unsigned int line;
    } result = {0, 0, 0};



    while (1){
        char *str;
        str = (char*) malloc(sizeof(char)*451);
        scanf(" %450[^\n]", str);

        if(*str=='.'){
            printf("Char = %u, word = %u, line = %u", result.character,result.word,result.line);
            free(str);
            break;
        }

        result.line += 1;

        char *ptr = str;
        int i = 0;
        int inWord = 0;
        while (*(ptr+i) != '\0') {

            if(isalpha((unsigned char)*(ptr+i))){
                result.character += 1;
            }
            if(!isspace((unsigned char)*(ptr+i))){
                if(!inWord){
                    result.word += 1;
                    inWord = 1;
                }
            } else {
                inWord = 0;
            }

            i++;
        }

        free(str);

    }
    

    return 0;
}