#include <stdio.h>
int main()
{
    int celsius;
    scanf("%d", &celsius);

    double fahrenheit = ((double)celsius * 9 / 5) + 32;
    
    printf("%.1lf\n", fahrenheit);
    return 0;
}