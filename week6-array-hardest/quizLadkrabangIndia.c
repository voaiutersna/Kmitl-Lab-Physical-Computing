#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
 
    int n;
    scanf("%d", &n);
    char text[3][10];
    double oil[n][3];
    double total[1][3] = {0,0,0};
    for(int i = 0;i<3;i++){
        scanf(" %s", text[i]);
    }
    for(int r = 0;r<n;r++){
        for(int c = 0;c<3;c++){
            scanf(" %lf", &oil[r][c]);
            total[0][c] += oil[r][c];
        }
    }
 
    for(int i = 0;i<3;i++){
        if(!strcmp(text[i],"Nano")){
            printf("Nano: %u refills\n", (unsigned int)ceil(total[0][i] / 6.6));
        }else if(!strcmp(text[i],"Toh")){
            printf("Toh: %u refills\n", (unsigned int)ceil(total[0][i] / 5.5));
        }else{
            printf("Mickey: %u refills\n", (unsigned int)ceil(total[0][i] / 5.5));        
        }
    }
 
    return 0;
}