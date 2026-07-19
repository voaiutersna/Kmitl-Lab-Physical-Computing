#include <stdio.h>

//Lab X-1: Device Registration Card
int main(){

    int device;
    char name[21];
    float num;
    char c;

    scanf("%d", &device);
    scanf("%s", name);
    scanf("%f", &num);
    scanf(" %c", &c);

    printf("Device #%d\n",device);
    printf("Name: %s\n", name);
    printf("Voltage: %.2fV\n",num);
    printf("Status: %c",c);

    return 0;
}