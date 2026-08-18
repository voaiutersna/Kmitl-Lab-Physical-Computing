#include <stdio.h>
#include <ctype.h>

int main(){

    char encode[] = {'Q','R','M','N','C','E','D','K','L','J','O','S','H','T','U','F','V','Z','G','W','I','A','B','X','Y','P'};
    int size = 26;
    char text[201];
    char result[201];
    scanf("%[^\n]", text);
    int index = 0;
    int i = 0;
    while(1){
        if(text[i] == '\0'){
            break;
        }
        if(text[i] == ' '){
            printf(" ");
            i++;
            continue;
        }

        for(int j = 0;j<size;j++){
            if(encode[j] == toupper(text[i])){

                index = (j-5+26) % 26;
                if(islower(text[i])){
                    printf("%c", tolower(encode[index]));
                }else{
                    printf("%c", encode[index]);
                }
                break;
            }
        }
        i++;
    }

    return 0;
}