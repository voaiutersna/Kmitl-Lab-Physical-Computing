#include <stdio.h>
int main(){

    float number;
    float num;
    char letter;

    scanf("%f", &number); //สามารถรับ int มาเป็น float data type ได้เลย
    scanf(" %f", &num);
    scanf(" %c", &letter); //รับ char สามารถแสดงเป็นตัวเลขได้อัติโนมัติ

    printf("%.3f\n", number);
    printf("%d\n", (int)num);     //convert floot to int ใช้ (int) เพื่อบอกว่าจะมีการ data loss
    printf("%d\n", letter);

}