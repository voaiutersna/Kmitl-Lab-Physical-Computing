// #include <stdio.h>

// int main(){
//     int num;
//     int l1,l2,l3,l4,l5;
//     scanf("%d", &num);
//     l1 = num/10000;
//     l2 = num/1000;
//     l3 = num/100;
//     l4 = num/10;
//     l5 = num/1;
//     printf("%d%c",l1,10);
//     printf("%3d%c",l2,10);
//     printf("%5d%c",l3,10);
//     printf("%7d%c",l4,10);
//     printf("%9d",l5);
//     return 0;
// }

#include <stdio.h>

int main() {
    char number[5];
    scanf("%s", number);
    printf("%-81.1s", number);
    printf("%-81.2s", number);
    printf("%-81.3s", number);
    printf("%-81.4s", number);
    printf("%-81.5s", number);

    return 0;
}