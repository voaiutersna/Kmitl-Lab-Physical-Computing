#include <stdio.h>

int main() {
    unsigned long long total_seconds, inp;
    unsigned long long day, hour, minute, second;

    scanf("%llu", &total_seconds);
    
    inp=total_seconds;
    day = total_seconds / 86400;
    total_seconds = total_seconds % 86400;
    hour = total_seconds / 3600;
    total_seconds = total_seconds % 3600;
    minute = total_seconds / 60;
    second = total_seconds % 60;
    
    printf("%llu s = %llu d %llu h %llu m %llu s\n", inp, day, hour, minute, second);
    
    return 0;
}