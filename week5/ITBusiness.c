#include <stdio.h>
#include <ctype.h>

int main(){

    double money,cash,n;
    char c;
    int error = 0;
    scanf("%lf", &money);
    scanf("%lf", &cash);
    while(1){
        
        if(scanf(" %c %lf", &c,&n) != 2) break;

        if(c=='E') break;
        else if(c=='D'){
            if(n>cash){
                error += 1;
                if(error == 3){
                    break;
                }
                continue;
            }
            cash -= n;
            money += n;
            error = 0;
            continue;

        }else if(c=='W'){
            if(n>money){
                error += 1;
                if(error == 3){
                    break;
                }
                continue;
            }
            cash += n;
            money -= n;
            error = 0;
            continue;
        }
        if(error == 3){
            break;
        }
    }

    printf("%.2lf\n", money);
    printf("%.2lf", cash);
    return 0;
}