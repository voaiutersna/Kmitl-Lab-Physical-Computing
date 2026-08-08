#include <stdio.h>
#include <stdbool.h>

int main(){

    int n;
    int inserted = 0;

    scanf("%d", &n);
    char c;
    char character[n][2];

    for(int i = 0;i<n;i++){
        scanf(" %c", &c);
        bool isinserted = false;
        for(int r = 0;r<=inserted;r++){
            if(c==character[r][0]){
                character[r][1] += 1;
                isinserted = true;
                break;
            }
        }
        if(isinserted==false){
            character[inserted][0] = c;
            inserted += 1;
        }
    }

    for(int r = 0;r<inserted;r++){
        printf("%d\n", character[r][1]);
    }

    return 0;
}