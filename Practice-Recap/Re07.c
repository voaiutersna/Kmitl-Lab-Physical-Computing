#include <stdio.h>

int main(){

    char name[31],lastname[31];
    int id,d,m,y;
    float gpa;

    scanf("%s",name);
    scanf("%s",lastname);
    scanf("%d", &id);
    scanf("%d/%d/%d", &d,&m,&y);
    scanf("%f", &gpa);

    printf("Fullname: %s %s\n",name,lastname);
    printf("ID: %d\n",id);
    printf("DOB: %02d-%02d-%04d\n", d,m,y);
    printf("GPA: %.2f\n",gpa);

    return 0;
}