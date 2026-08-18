#include <stdio.h>
#include <ctype.h>

int main(){
    char letters[26] = {0};
    int counts[26] = {0};
    int unique = 0;
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        char ch;
        scanf(" %c", &ch);
        ch = tolower(ch);

        int found = 0;
        for (int j = 0; j < unique; j++){
            if (letters[j] == ch){
                counts[j]++;
                found = 1;
                break;
            }
        }
        if (!found && ch >= 'a' && ch <= 'z'){
            letters[unique] = ch;
            counts[unique] = 1;
            unique++;
        }
    }

    for (int i = 0; i < unique; i++){
        printf("%c: %d\n", letters[i], counts[i]);
    }

    return 0;
}
