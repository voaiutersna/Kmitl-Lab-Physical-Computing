#include <stdio.h>

//Lab X-2: Odometer Readout
int main(){

    int meter,km;

    scanf("%d", &meter);

    km = meter / 1000;
    meter = meter % 1000;

    printf("Distance: %d km %d m",km,meter);

    return 0;
}