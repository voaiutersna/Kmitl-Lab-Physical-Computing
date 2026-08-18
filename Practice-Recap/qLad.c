#include <stdio.h>
#include <math.h>
#include <string.h>
int main() {

    int n;
    scanf("%d", &n);
    char name[3][10];
    for(int i = 0;i<3;i++){
        scanf("%s", name[i]);
    }
    double oil[n][3];
    double total[3] = {0,0,0};
    for(int r=0;r<n;r++){
        for(int c=0;c<3;c++){
            scanf(" %lf", &oil[r][c]);
            total[c] += oil[r][c];
        }
    }

    for(int i = 0;i<3;i++){
        if(!strcmp(name[i],"Nano")){
            printf("Nano: %.0lf refills\n", ceil(total[i]/6.6));
        }else if(!strcmp(name[i],"Toh")){
            printf("Toh: %.0lf refills\n", ceil(total[i]/5.5));
        }else if(!strcmp(name[i],"Mickey")){
            printf("Mickey: %.0lf refills\n", ceil(total[i]/5.5));
        }
    }

    return 0;
}
