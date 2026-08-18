#include <stdio.h>
#include <ctype.h>

int main(){

    char t[301];
    int result[301];
    char find;
    int inserted = 0;
    scanf("%[^\n]", t);
    scanf(" %c",&find);
    int i = 0;
    while(1){
        if(t[i]=='\0'){
            break;
        }
        if(tolower(t[i])==tolower(find)){
            result[inserted] = i+1;
            inserted += 1;
        }
        i+=1;
    }
    if(inserted == 0){
        printf("Not found.");
        return 0;
    }
    printf("There is/are %d \"%c\" in the above sentences.\n", inserted,find);
    printf("Position:");
    for(int i = 0;i<inserted;i++){
        if(i!=inserted-1){
            printf(" %d,",result[i]);
            continue;
        }
        printf(" %d",result[i]);
    }

    return 0;
}