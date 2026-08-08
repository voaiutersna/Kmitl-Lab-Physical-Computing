#include <stdio.h>
#include <ctype.h>

int main(){

    char encode[] = {'Q','R','M','N','C','E','D','K','L','J','O','S','H','T','U','F','V','Z','G','W','I','A','B','X','Y','P'};
    int size = 26;
    char text[201];
    scanf("%[^\n]", text);

    int i = 0;
    while(1){

        if(text[i]=='\0') break;
        if(text[i]==' '){
            printf("%s"," ");
            i++;
            continue;
        }
        for(int j = 0;j<size;j++){
            if(encode[j] == toupper(text[i])){
                //(j - shift + size) % size
                int newIndex = (j + 5 + size) % size;
                if(islower(text[i])){
                    printf("%c", tolower(encode[newIndex]));
                    break;
                }
                printf("%c", encode[newIndex]);
                break;
            }
        }
        i++;

    }

    return 0;
}