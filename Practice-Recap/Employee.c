#include <stdio.h>

int main(){

    char firstname[41], lastname[41];
    int n1,n2,n3,n4;
    
    scanf("%s %s", firstname, lastname);
    scanf("%d %d %d %d", &n1,&n2,&n3,&n4);

    printf("Performance Report: %s %s\n", firstname, lastname);
    printf("Score: %.2lf", ((double)(n1+n2+n3+n4)/20) * 100);

    return 0;
}