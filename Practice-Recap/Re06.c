#include <stdio.h>

int main(){

    char inp1[31];
    char inp2[31];
    char inp3[31];
    char inp4[31];

    scanf("%s", inp1);
    scanf("%s", inp2);
    scanf("%s", inp3);
    scanf("%s", inp4);

    printf("String 1:%4.3s\n", inp1);
    printf("String 2:%5.4s\n", inp2);
    printf("String 3:%6.5s\n", inp3);
    printf("String 4:%7.6s\n", inp4);
    return 0;
}