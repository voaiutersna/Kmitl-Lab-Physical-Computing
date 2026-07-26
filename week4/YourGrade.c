#include <stdio.h>

int main(){

    char inp;

    scanf("%c", &inp);

    switch (inp)
    {
    case 'A':
        printf("%s", "Genius");
        break;
    case 'a':
        printf("%s", "Genius");
        break;
    case 'B':
        printf("%s", "Good");
        break;
    case 'b':
        printf("%s", "Good");
        break;
    case 'C':
        printf("%s", "Try Harder");
        break;
    case 'c':
        printf("%s", "Try Harder");
        break;
    case 'D':
        printf("%s", "Very Bad");
        break;
    case 'd':
        printf("%s", "Very Bad");
        break;
    case 'F':
        printf("%s", "Fail");
        break;
    case 'f':
        printf("%s", "Fail");
        break;
    default:
        printf("%s", "Invalid Input");
        break;
    }

    return 0;
}