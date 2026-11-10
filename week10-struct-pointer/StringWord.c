#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void to_lower(char* str){
    for(int i = 0; str[i] != '\0'; i++){
        str[i] = tolower(str[i]);
    }
}

int main(){

    char* str = (char*) malloc(sizeof(char)*151);   // 150 ตัว + '\0'
    char* words[150];                                // เก็บ pointer ไปยังต้นของแต่ละคำ
    int count = 0;

    scanf("%150[^\n]", str);
    to_lower(str);

    // strtok ตัด string ตาม space แล้วคืน pointer ไปที่คำทีละคำ
    char* token = strtok(str, " ");
    while(token != NULL){
        words[count] = token;
        count++;
        token = strtok(NULL, " ");
    }

    printf("%d words\n", count);
    printf("----\n");
    for(int i = 0; i < count; i++){
        printf("%s : %d\n", words[i], (int) strlen(words[i]));
    }

    free(str);
    return 0;
}
