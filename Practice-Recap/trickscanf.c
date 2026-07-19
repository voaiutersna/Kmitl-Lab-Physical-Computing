#include <stdio.h>

/*
วิธีรันทดสอบทีละเทคนิค: comment เทคนิคอื่นออกใน main() เหลือไว้แค่ตัวที่จะลอง
เพราะทุกเทคนิคแย่งกันอ่านจาก stdin ตัวเดียวกัน ถ้าเปิดพร้อมกันหลายตัว
ต้องพิมพ์ input ให้ครบตามลำดับที่แต่ละเทคนิคต้องการต่อเนื่องกันไปเรื่อยๆ
*/

// เทคนิค 1: เว้นวรรคคั่น (พื้นฐานที่สุด)
// sample input: 1 2 3
void technique1(){
    int a, b, c;
    printf("[1] เว้นวรรคคั่น - พิมพ์: 1 2 3\n");
    scanf("%d %d %d", &a, &b, &c);
    printf("    a=%d b=%d c=%d\n\n", a, b, c);
}

// เทคนิค 2: จำกัดความกว้าง (%1d ตัดทีละหลัก, %2s ตัดทีละ 2 ตัวอักษร)
// sample input: 123 แล้ว abcd
void technique2(){
    int a, b, c;
    char word1[3], word2[3];

    printf("[2] จำกัดความกว้าง %%1d - พิมพ์ติดกัน: 123\n");
    scanf("%1d%1d%1d", &a, &b, &c);
    printf("    a=%d b=%d c=%d\n", a, b, c);

    printf("[2] จำกัดความกว้าง %%2s - พิมพ์ติดกัน: abcd\n");
    scanf("%2s%2s", word1, word2);
    printf("    word1=%s word2=%s\n\n", word1, word2);
}

// เทคนิค 3: มีตัวคั่นตายตัวฝังใน format string (เช่นรูปแบบวันที่)
// sample input: 25/12/2026
void technique3(){
    int d, m, y;
    printf("[3] ตัวคั่นตายตัว %%d/%%d/%%d - พิมพ์: 25/12/2026\n");
    scanf("%d/%d/%d", &d, &m, &y);
    printf("    day=%d month=%d year=%d\n\n", d, m, y);
}

// เทคนิค 4: อ่านเข้า array ด้วย loop (จำนวนไม่คงที่ ผู้ใช้บอกจำนวนก่อน)
// sample input: 5 แล้ว 10 20 30 40 50
void technique4(){
    int arr[100], n;
    printf("[4] อ่านเข้า array ด้วย loop - พิมพ์: 5 แล้ว 10 20 30 40 50\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("    array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

// เทคนิค 5: อ่านทีละตัวอักษรด้วย getchar() (ควบคุมละเอียดที่สุด)
// sample input: Hello แล้ว Enter
void technique5(){
    char c;
    printf("[5] getchar() ทีละตัวอักษร - พิมพ์: Hello แล้วกด Enter\n");
    printf("    อ่านได้: ");

    // getchar() ก็ไม่ข้าม whitespace ให้อัตโนมัติเหมือน %c/%[...] จึงต้องไล่ข้าม \n
    // ที่ค้างมาจาก scanf ตัวก่อนหน้าเองก่อน ค่อยเริ่มอ่านตัวอักษรจริง
    while((c = getchar()) == '\n' || c == ' ' || c == '\t');

    while(c != '\n'){
        printf("[%c]", c);
        c = getchar();
    }
    printf("\n\n");
}

// เทคนิค 6: fgets + sscanf (ปลอดภัยสุด ไม่มีปัญหา \n ค้าง)
// sample input: 7 8 9
void technique6(){
    char line[100];
    int a, b, c;
    printf("[6] fgets + sscanf - พิมพ์: 7 8 9\n");
    fgets(line, sizeof(line), stdin);      // อ่านทั้งบรรทัดเก็บเป็น string ก่อน กิน \n ไปด้วยในตัว
    sscanf(line, "%d %d %d", &a, &b, &c);  // ค่อยแกะค่าจาก string ทีหลัง
    printf("    a=%d b=%d c=%d\n\n", a, b, c);
}

int main(){
    technique1();
    technique2();
    technique3();
    technique4();
    technique5();
    technique6();

    return 0;
}
