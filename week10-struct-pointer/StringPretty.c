#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_border(int width){
    for(int i = 0; i < width; i++){
        printf("*");
    }
    printf("\n");
}

void print_spaces(int n){
    for(int i = 0; i < n; i++){
        printf(" ");
    }
}

void print_center(char* text, int width){
    int space = (width - 2) - strlen(text);   // ช่องว่างทั้งหมดภายในกล่อง (ไม่รวม * สองข้าง)
    int left = (space + 1) / 2;                // ถ้าเป็นเลขคี่ ซ้ายได้มากกว่า 1 ช่อง → เยื้องขวา
    int right = space / 2;

    printf("*");
    print_spaces(left);
    printf("%s", text);
    print_spaces(right);
    printf("*\n");
}

int main(){

    int width;
    char* text1 = (char*) malloc(sizeof(char)*51);   // ยาวไม่เกิน 50 + '\0'
    char* text2 = (char*) malloc(sizeof(char)*41);   // ยาวไม่เกิน 40 + '\0'

    scanf("%d", &width);
    scanf(" %50[^\n]", text1);
    scanf(" %40[^\n]", text2);

    print_border(width);
    print_center(text1, width);
    print_center(text2, width);
    print_border(width);

    free(text1);
    free(text2);
    return 0;
}
