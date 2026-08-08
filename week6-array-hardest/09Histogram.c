#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
int main(){

    int n;
    int inserted = 0;

    scanf("%d", &n);
    char c;
    char character[n];
    int count[n];
    for(int i = 0;i<n;i++){
        scanf(" %c", &c);
        c = tolower(c);
        bool isinserted = false;
        for(int r = 0;r<=inserted;r++){
            if(c==character[r]){
                count[r] += 1;
                isinserted = true;
                break;
            }
        }
        if(isinserted==false){
            character[inserted] = c;
            count[inserted] = 1;
            inserted += 1;
        }
    }

    for(int r = 0;r<inserted;r++){
        printf("%c: ", character[r]);
        printf("%d\n", count[r]);
    }

    return 0;
}