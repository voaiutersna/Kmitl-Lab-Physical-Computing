#include <stdio.h>
#include <ctype.h>

int main(){

    double money,cash,n;
    char c;
    int error = 0;
    scanf("%lf", &money);
    scanf("%lf", &cash);
    while(1){
        
        scanf(" %c %lf", &c,&n);

        if(c=='E') break;
        else if(c=='D' && n<=cash){
            cash -= n;
            money += n;
            error = 0;
            continue;

        }else if(c=='W' && n<=money){
            cash += n;
            money -= n;
            error = 0;
            continue;
        }
        error += 1;
        if(error == 3){
            break;
        }
    }

    printf("%.2lf\n", money);
    printf("%.2lf", cash);
    return 0;
}