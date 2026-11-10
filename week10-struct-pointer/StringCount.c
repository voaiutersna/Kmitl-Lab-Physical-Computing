#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count_char(char* str, char target){

    int count = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(tolower(str[i]) == tolower(target)){   // ไม่สนตัวเล็ก/ตัวใหญ่
            count++;
        }
    }
    return count;
}

int main(){

    char target;
    char* str = (char*) malloc(sizeof(char)*151);   // 150 ตัว + '\0'

    scanf(" %c", &target);
    scanf(" %150[^\n]", str);

    printf("%d\n", count_char(str, target));

    free(str);
    return 0;
}
