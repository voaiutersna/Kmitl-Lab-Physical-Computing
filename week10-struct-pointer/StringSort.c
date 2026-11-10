#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// bubble sort ตามค่า ASCII จากน้อยไปมาก
void sort_string(char* str){

    int n = strlen(str);
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(str[j] > str[j+1]){
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}

int main(){

    char* str = (char*) malloc(sizeof(char)*201);   // 200 ตัว + '\0'

    scanf("%200[^\n]", str);

    remove_space(str);
    sort_string(str);
    printf("%s\n", str);

    free(str);
    return 0;
}
