#include <stdio.h>
#include <stdlib.h>

// ลบกลุ่มตัวอักษรเดียวกันที่อยู่ติดกันออก 1 รอบ
// คืนค่า 1 ถ้ามีการลบ, 0 ถ้าไม่มีอะไรให้ลบแล้ว
int remove_adjacent(char* str){

    int i = 0;
    int j = 0;
    int removed = 0;

    while(str[i] != '\0'){
        int k = i;
        while(str[k] == str[i]){   // หาว่าตัวเดียวกันติดกันไปถึงไหน
            k++;
        }
        if(k - i >= 2){            // ติดกันตั้งแต่ 2 ตัว → ข้ามทั้งกลุ่ม (ลบ)
            removed = 1;
        }else{                     // ตัวเดียว → เก็บไว้
            str[j] = str[i];
            j++;
        }
        i = k;
    }
    str[j] = '\0';

    return removed;
}

int main(){

    char* str = (char*) malloc(sizeof(char)*101);   // 100 ตัว + '\0'

    scanf("%100[^\n]", str);

    while(remove_adjacent(str)){
        printf("%s\n", str);
    }

    free(str);
    return 0;
}
