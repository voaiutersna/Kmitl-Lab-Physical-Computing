#include <stdio.h>

int main() {
    int age, day;
    scanf("%d", &age);
    scanf("%d", &day);

    int total;

    if (day == 4) {
        total = 100;
    } else if (age <= 12) {
        total = 120;
    } else if (age <= 59) {
        total = 220;
    } else {
        total = 140;
    }

    if (day == 1 || day == 7) {
        total += 20;
    }

    printf("Ticket price: %d Baht", total);

    return 0;
}
