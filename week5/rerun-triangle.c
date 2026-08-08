#include <stdio.h>

int main(){

    int n;
    unsigned int result = 0;
    scanf("%d", &n);
    for(int i = 1;i<=n;i++){
        result += i;
    }
    printf("%u", result);

    return 0;
}