#include <stdio.h>
#include <stdlib.h>

void remove_space(char* str){

    int j = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] != ' '){
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

int main(){

    char* str;
    str = (char*) malloc(sizeof(char)*151);   // 150 ตัว + '\0'

    scanf("%150[^\n]", str);

    remove_space(str);
    printf("%s\n", str);

    free(str);
    return 0;
}
