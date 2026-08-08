#include <stdio.h>
#include <math.h>

void swapD(double *a, double *b) {
    double t = *a;
    *a = *b;
    *b = t;
}

int partition(double num[], int low, int high) {
    double pivot = num[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (num[j] <= pivot) {
            i++;
            swapD(&num[i], &num[j]);
        }
    }
    swapD(&num[i + 1], &num[high]);
    return i + 1;
}

void quickSort(double num[], int low, int high) {
    if (low < high) {
        int p = partition(num, low, high);
        quickSort(num, low, p - 1);   // ซ้าย pivot
        quickSort(num, p + 1, high);  // ขวา pivot
    }
}

int main(){
    int n;
    scanf("%d", &n);
    double num[n];
    double total = 0;
    double sumSq = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lf", &num[i]);
        total += num[i];
        sumSq += num[i] * num[i];
    }
    double avg = total / n;
    printf("%.2lf\n", avg);

    quickSort(num, 0, n - 1);

    if (n % 2 == 0) {
        double med = (num[n / 2 - 1] + num[n / 2]) / 2.0;
        printf("%.2lf\n", med);
    } else {
        printf("%.2lf\n", num[n / 2]);
    }
    double sd = sqrt(sumSq / n - avg * avg);
    printf("%.2lf", sd);

    return 0;
}
