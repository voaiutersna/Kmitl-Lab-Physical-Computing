#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){

    int n;
    double total = 0;
    char name[10];
    int result;

    scanf("%d %[^\n]", &n,name);
    for (int i = 1; i<=n; i++){
        double oil;
        scanf("%lf", &oil);
        total += oil;
    }

    if(!strcmp(name,"Nano")){
        result = ceil(total/6.6);
        printf("Nano: %d refills", result);
    }else if(!strcmp(name,"Mickey")){
        result = ceil(total/5.5);
        printf("Mickey: %d refills", result);

    }else if(!strcmp(name,"Copter")){
        result = ceil(total/4.4);
        printf("Copter: %d refills", result);

    }
    
    return 0;
}