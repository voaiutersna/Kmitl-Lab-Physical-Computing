#include <stdio.h>

int main(){
    // %% ใน printf หมายถึงเครื่องหมาย % ตัวจริงหนึ่งตัว (literal %)
    // ถ้าเขียนแค่ % ตัวเดียว printf จะพยายามตีความตัวถัดไปเป็น format specifier แทน
    // \" คือ escape เครื่องหมายคำพูดให้พิมพ์ " ออกมาจริงๆ, \\ คือ escape backslash ให้พิมพ์ \ ออกมาจริงๆ
    printf("\"_'Hello#\\%%_%%/#$My$#\\%%_%%/#ChefIan'_\"");

    return 0;
}