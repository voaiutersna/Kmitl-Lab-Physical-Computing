#include <stdio.h>

int main(){

    char name[31], lastname[31], name02[31], lastname02[31], name03[31];

    scanf("%s", name);
    scanf("%s", lastname);
    scanf("%s %s", name02, lastname02);
    scanf(" %[^\n]", name03);

    printf("Person 1: %s %s\n", name, lastname);
    printf("Person 2: %s %s\n", name02, lastname02);
    printf("Person 3: %s\n", name03);

    return 0;
}