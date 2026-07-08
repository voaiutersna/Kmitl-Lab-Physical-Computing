#include <stdio.h>

int main(){
    float f_number = 3.1415;
    int number1 = 12345;
    int number2 = -6789;
    int number3 = 24500;

    printf("123456789012345678901234567890\n");
    printf("%d %d %d\n", number1, number2, number3);

    //%3d บอกว่า "ต้องการความกว้างอย่างน้อย 3 ช่อง" แต่ตัวเลขจริงมี 5 หลักอยู่แล้ว กว้างเกิน 3 ไปแล้ว ดังนั้น width จึงไม่มีผลอะไรเลย เพราะมันเป็นแค่ค่าขั้นต่ำ (ถ้าตัวเลขสั้นกว่าถึงจะเห็นผล เช่น เติมช่องว่างนำหน้า)
    printf("%3d %3d %3d\n", number1, number2, number3);
    printf("%8d %8d %8d\n", number1, number2, number3);

    //%08d เติม0ข้างหน้าและมีความกว้างอย่างน้อย8
    printf("%08d %08d %08d\n", number1, number2, number3);

    //ชิดซ้าย
    printf("%-8d %-8d %-8d\n", number1, number2, number3);
    printf("%10f\n", f_number);
    printf("%3f\n", f_number);
    printf("%-10f\n", f_number);

    //ทศนิยม3ตำแหน่ง ชิดซ้าย
    printf("%-10.3f\n", f_number);
    printf("%10.2f\n", f_number);
    
    //ไม่กำหนดขนาด แต่ทศนิยม1ตำแหน่ง
    printf("%.1f\n", f_number);
    printf("%.3f\n", f_number);

    return 0;
}