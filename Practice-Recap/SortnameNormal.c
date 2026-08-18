#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main(){

    int size = 20;
    int j = 0;
    char student[20][61];
    int length[20];
    bool nextupper = false;

    //setup
    for(int i = 0;i<size;i++){
        scanf(" %[^\n]", student[i]);
        j = 1;
        student[i][0] = toupper(student[i][0]);
        while(1){
            if(student[i][j]== '\0'){
                break;
            }
            if(student[i][j]==' '){
                nextupper = true;
                j+=1;
                continue;
            }
            if(nextupper){
                nextupper = false;
                student[i][j] = toupper(student[i][j]);
                j+=1;
                continue;
            }
            student[i][j] = tolower(student[i][j]);
            j+=1;
        }
        length[i] = j;
    }

    // sort part
    for(int i = 0;i<size;i++){
        bool issorted = true; 
        for(int k=0;k<size-i-1;k++){
            int until;
            if(length[k]<length[k+1]){
                until=length[k];
            }else{
                until=length[k+1];
            }
            bool isabove = false;
            int z = 0;
            while(z<until){
                if(student[k][z] > student[k+1][z]){
                    isabove = true;
                    break;
                }else if(student[k][z] < student[k+1][z]){
                    break;
                }
                z++;
            }

            //swap string
            char temp[61];
            if(isabove == true){
                //copy to temp
                int a = 0;
                while(1){
                    if(student[k][a]=='\0'){
                        break;
                    }
                    temp[a] = student[k][a];
                    a++;
                }
                temp[a] = '\0';
                
                // copy student[k+1] -> student[k]
                a = 0;
                while(1){
                    if(student[k+1][a]=='\0'){
                        break;
                    }
                    student[k][a] = student[k+1][a];
                    a++;
                }
                student[k][a] = '\0';
                // copy temp -> student[k+1]
                a = 0;
                while(1){
                    if(temp[a]=='\0'){
                        break;
                    }
                    student[k+1][a] = temp[a];
                    a++;
                }
                student[k+1][a] = '\0';

                int templ = length[k];
                length[k] = length[k+1];
                length[k+1] = templ;

                issorted = false;
            }
        }

        if(issorted==true){
            break;
        }
    }

    //output
    // printf("----\n");
    for(int i = 0;i<size;i++){
        printf("%s\n", student[i]);
    }
    // printf("%d",length[0]);
    

    return 0;
}