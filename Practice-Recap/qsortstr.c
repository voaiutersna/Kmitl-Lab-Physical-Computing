#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int compare_str(const void *a, const void *b){
    return strcmp((const char*)a, (const char*)b);
    // strcmp คืนค่าตรงตาม convention เดียวกับที่ qsort ต้องการอยู่แล้ว!
}

int main(){
    char names[][20] = {"Charlie", "Alice", "Bob"};
    qsort(names, 3, sizeof(names[0]), compare_str);

    for(int i = 0; i < 3; i++){
        printf("%s\n", names[i]);
    }
}