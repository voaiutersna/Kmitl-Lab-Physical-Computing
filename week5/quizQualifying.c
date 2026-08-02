#include <stdio.h>

int main(){

    double t1,t2,t3;
    char n1[36],n2[36],n3[36];

    scanf("%lf %[^\n]", &t1,n1);
    scanf(" %lf %[^\n]", &t2,n2);
    scanf(" %lf %[^\n]", &t3,n3);

    if(t1<=t2 && t1<=t3){
        printf("%s is Fastest : %.3lf", n1,t1);
    }else if(t2<=t3 && t2<=t1){
        printf("%s is Fastest : %.3lf", n2,t2);
    }else{
        printf("%s is Fastest : %.3lf", n3,t3);
    }

}