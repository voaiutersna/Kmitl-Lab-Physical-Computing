#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
int main(){

    char t1[102];
    char t2[102];
    scanf("%[^\n]", t1);
    scanf(" %[^\n]", t2);

    int len1 = strlen(t1);
    int len2 = strlen(t2);
    
    for(int i = 0;i<len1;i++){
        if(islower(t1[i])){
            t1[i] = toupper(t1[i]);
        }else{
            t1[i] = tolower(t1[i]);
        }
    }

    for(int i = 0;i<len2;i++){
        if(islower(t2[i])){
            t2[i] = toupper(t2[i]);
        }else{
            t2[i] = tolower(t2[i]);
        }
    }

    if(len1>len2 || len1<len2){
        printf("*** Results ***\n");
        printf("%s\n", t1);
        printf("%s\n", t2);
        printf("***************\n");
        printf("Both strings are not the same.");
        return 0;
    }

    bool issame = true;
    for(int i = 0 ;i<len1 ;i++){
        if(tolower(t1[i])!=tolower(t2[i])){
            issame = false;
        }
    }
    if(issame){
        printf("*** Results ***\n");
        printf("%s\n", t1);
        printf("%s\n", t2);
        printf("***************\n");
        printf("Both strings are the same.");
    }else{
        printf("*** Results ***\n");
        printf("%s\n", t1);
        printf("%s\n", t2);
        printf("***************\n");
        printf("Both strings are not the same.");
    }



}