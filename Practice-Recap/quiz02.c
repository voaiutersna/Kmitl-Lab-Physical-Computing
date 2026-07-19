#include <stdio.h>

int main(){

    char name[21], last[21], id[9], nick[21];
    scanf("%s %s", name,last);
    scanf("%s", nick);
    scanf("%s", id);

    printf("Hello World, my name is %s (%s)\n\n", nick, name);
    printf("Student ID: %s\n",id);
    printf("Name: %s %s\n", name,last);
    printf("Nickname: %s", nick);
    return 0;
}