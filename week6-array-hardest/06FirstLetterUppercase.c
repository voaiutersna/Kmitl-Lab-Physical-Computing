#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main(){

    char name1[61],name2[61];

    scanf("%[^\n]", name1);
    scanf(" %[^\n]", name2);

    int i = 0;
    bool second = false;
    while(1){
        if(name1[i] == '\0'){
            break;
        }
        if(i==0){
            name1[0] = toupper(name1[0]);
            i++;
            continue;
        }
        if(name1[i] == ' '){
            second = true;
            i++;
            continue;
        }
        if(second == true){
            name1[i] = toupper(name1[i]);
            second = false;
            i++;
            continue;
        }
        name1[i] = tolower(name1[i]);
        i++;
    }

    i = 0;
    second = false;
    while(1){
        if(name2[i] == '\0'){
            break;
        }
        if(i==0){
            name2[0] = toupper(name2[0]);
            i++;
            continue;
        }
        if(name2[i] == ' '){
            second = true;
            i++;
            continue;
        }
        if(second == true){
            name2[i] = toupper(name2[i]);
            second = false;
            i++;
            continue;
        }
        name2[i] = tolower(name2[i]);
        i++;
    }

    printf("%s\n", name1);
    printf("%s", name2);

    return 0;
}