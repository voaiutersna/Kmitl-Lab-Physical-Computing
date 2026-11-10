#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void to_lower(char* str){
    for(int i = 0; str[i] != '\0'; i++){
        str[i] = tolower(str[i]);
    }
}

void find_cat(char* str){

    int first = 1;
    char* pos = strstr(str, "cat");          // หา "cat" ตัวแรก

    while(pos != NULL){
        int index = (int)(pos - str);        // ลบ address → ได้ตำแหน่ง (เริ่ม 0 ตาม Sample)

        if(!first){
            printf(", ");
        }
        printf("%d", index);
        first = 0;

        pos = strstr(pos + 1, "cat");        // หาต่อจากตำแหน่งถัดไป
    }
    printf("\n");
}

int main(){

    char* str = (char*) malloc(sizeof(char)*2001);   // 2000 ตัว + '\0'

    scanf("%2000[^\n]", str);

    to_lower(str);      // ทำเป็นตัวเล็กหมดก่อน จะได้หา "cat" อย่างเดียวพอ
    find_cat(str);

    free(str);
    return 0;
}
