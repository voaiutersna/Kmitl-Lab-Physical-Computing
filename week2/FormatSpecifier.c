#include <stdio.h>
int main(){
	int number;
	float num;
	char letter;
	char text[21];

	scanf("%d", &number);
	scanf(" %f", &num);
	scanf(" %c", &letter);
	scanf("%s", text);

	printf("Integer: %d\n",number);
	printf("Float: %.3f\n", num);
	printf("Character: %c\n", letter);
	printf("String: %s\n", text);
}
