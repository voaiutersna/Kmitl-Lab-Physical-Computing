#include <stdio.h>
int main(){

	char firstname[21], lastname[21];
    char nickname[21];
    char text02[21];
	scanf("%s %s", firstname, lastname);
    scanf("%s", nickname);
    scanf("%s", text02);

    printf("Hello World, my name is %s (%s)\n", nickname, firstname);
    printf("\n");
    printf("Student ID: %s\n", text02);
    printf("Name: %s %s\n",firstname, lastname);
    printf("Nickname: %s", nickname);
}
