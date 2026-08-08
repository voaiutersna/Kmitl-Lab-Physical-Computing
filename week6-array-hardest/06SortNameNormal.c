#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(){

    char name[20][61];
    int length[20];
    // scanf("%[^\n]",name[0]);
    // printf("%s", name[0]);

    for(int i = 0;i<20;i++){
        scanf(" %[^\n]",name[i]);
        int j = 0;
        bool second = false;
        while(1){
        if(name[i][j] == '\0'){
            length[i] = j;
            break;
        }
        if(j==0){
            name[i][0] = toupper(name[i][0]);
            j++;
            continue;
        }
        if(name[i][j] == ' '){
            second = true;
            j++;
            continue;
        }
        if(second == true){
            name[i][j] = toupper(name[i][j]);
            second = false;
            j++;
            continue;
        }
        name[i][j] = tolower(name[i][j]);
        j++;
        }
    }
    // printf("%s", name[0]);
    // printf("%d", length[0]);

    for(int i = 0;i<20;i++){
        for(int j = 0;j<20-i-1;j++){
            bool isabove = false;

            int until = 0;
            if(length[j]<=length[j+1]){
                until = length[j];
            }else{
                until = length[j+1];
            }

            int k=0;
            while(k<until){
                if(name[j][k]>name[j+1][k]){
                    isabove = true;
                    break;
                }else if(name[j][k]<name[j+1][k]){
                    break;
                }
                k++;
            }

            if(isabove){
                char temp[61];
                int t = 0;
                // copy name[j] -> temp
                while(name[j][t] != '\0'){
                    temp[t] = name[j][t];
                    t++;
                }
                temp[t] = '\0';

                // copy name[j+1] -> name[j]
                t = 0;
                while(name[j+1][t] != '\0'){
                    name[j][t] = name[j+1][t];
                    t++;
                }
                name[j][t] = '\0';

                // copy temp -> name[j+1]
                t = 0;
                while(temp[t] != '\0'){
                    name[j+1][t] = temp[t];
                    t++;
                }
                name[j+1][t] = '\0';

                int tlen = length[j];
                length[j] = length[j+1];
                length[j+1] = tlen;
            }
        } 
    }

    for(int i = 0;i<20;i++){
        printf("%s\n",name[i]);
    }

    return 0;
}