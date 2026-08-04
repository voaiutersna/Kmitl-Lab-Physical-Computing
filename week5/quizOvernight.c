#include <stdio.h>

int main(){

    int n;
    double blood = 2800;
    double total = 0;
    scanf("%d",&n);

    int fullhour = n/2;
    double safe = blood - (blood*(30.0/100));
    for (int i=1;i<=fullhour;i++){
        // printf("Come in");
        double minus = blood*(2.0/100);
        total += minus;
        blood -= minus;
        // printf("%lf\n",minus);
        // printf("%lf\n",blood);
    }

    if(blood>=safe){
        printf("%.2lf\n", total);
        printf("Safe");
    }else{
        printf("%.2lf\n", total);
        printf("Danger");
    }
    return 0;

}