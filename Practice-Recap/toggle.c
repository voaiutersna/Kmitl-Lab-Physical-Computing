#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
int main(){
    
    char t1[102];
    char t2[102];
    int s1,s2;
    scanf(" %[^\n]",t1);
    scanf(" %[^\n]",t2);
    s1 = strlen(t1);
    s2 = strlen(t2);
    // printf("%d %d",s1,s2);
    bool issame = true;
    if(s1!=s2){
        for(int i = 0;i<s1;i++){
            if(islower(t1[i])){
                t1[i] = toupper(t1[i]);
            }else{
                t1[i] = tolower(t1[i]);
            }
        }
        for(int i = 0;i<s2;i++){
            if(islower(t2[i])){
                t2[i] = toupper(t2[i]);
            }else{
                t2[i] = tolower(t2[i]);
            }
        }
        printf("*** Results ***\n");
        printf("%s\n",t1);
        printf("%s\n",t2);
        printf("***************\n");
        printf("Both strings are not the same.");
        return 0;


    }else{
    for(int i = 0;i<s1;i++){
            if(islower(t1[i])){
                t1[i] = toupper(t1[i]);
            }else{
                t1[i] = tolower(t1[i]);
            }
            if(islower(t2[i])){
                t2[i] = toupper(t2[i]);
            }else{
                t2[i] = tolower(t2[i]);
            }
            if(tolower(t1[i])!=tolower(t2[i])){
                issame=false;
            }
        }
    }
    printf("*** Results ***\n");
    printf("%s\n",t1);
    printf("%s\n",t2);
    printf("***************\n");
    if(issame){
        printf("Both strings are the same.\n");
    }else{
        printf("Both strings are not the same.");
    }
   


    return 0;
}