#include <stdio.h>

int main(){

    char info[41];
    int g1, g2, g3, g4, g5, g6;

    // Your code here
    scanf("%[^\n]", info);
    scanf("%d %d %d %d %d %d", &g1,&g2,&g3,&g4,&g5,&g6);

    printf("Grade announcement 1/2568: %s\n",info);
    printf("GPS/GPA: %.2lf", (g1+g2+g3+g4+g5+g6) / ((double) 6));
    

    return 0;
}