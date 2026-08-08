#include <stdio.h>
#include <math.h>
int main(){

    int n;
    scanf("%d", &n);
    double num[n];
    double total=0;
    double temp=0;
    for (int i = 0;i<n;i++){
        scanf("%lf", &num[i]);
        total += num[i];
    }
    double avg = total/n;
    printf("%.2lf\n", avg);

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-i-1;j++){
            if(num[j]>num[j+1]){
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }
    if(n%2==0){
        int index=n/2-1;
        double med = (num[index]+num[index+1])/ 2.0;
        printf("%.2lf\n", med);
    }else{
        printf("%.2lf\n", num[(int)ceil(n/2)]);
    }

    // for(int i = 0;i<n;i++){
    //     printf("%lf ", num[i]);
    // }

    double sd;
    double sum = 0;
    for(int i = 0;i<n;i++){
        sum+=(num[i]-avg)*(num[i]-avg);
    }
    sd = sqrt(sum/n);
    printf("%.2lf", sd);
}