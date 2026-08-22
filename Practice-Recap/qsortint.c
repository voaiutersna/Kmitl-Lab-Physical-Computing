#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    double x = *(double*)a;
    double y = *(double*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main(){
    double arr[] = {5, 2, 9, 1, 7};
    int n = 5;
    qsort(arr, n, sizeof(double), compare);
    for(int i = 0; i < n; i++){
        printf("%lf ", arr[i]);
    }
    return 0;
}