#include <stdio.h>

long long way(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }

    return way(n - 1) + way(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);

    printf("method = %lld\n", way(n));

    return 0;
}
