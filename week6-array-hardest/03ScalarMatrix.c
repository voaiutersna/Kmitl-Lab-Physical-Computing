#include <stdio.h>
#include <stdbool.h>
int main(){

    double m[3][3];
    bool isscalar = true;
    scanf("%lf %lf %lf", &m[0][0], &m[0][1], &m[0][2]);
    scanf("%lf %lf %lf", &m[1][0], &m[1][1], &m[1][2]);
    scanf("%lf %lf %lf", &m[2][0], &m[2][1], &m[2][2]);
    double checker = m[0][0];

    for(int r = 0;r<3;r++){
        for(int c = 0;c<3;c++){
            // printf("%lf ", m[r][c]);
            if(c==r && (checker != m[r][c])){
                isscalar = false;
                break;
            }
            if(c!=r && m[r][c] != 0.0){
                isscalar = false;
                break;
            }
        }
        // printf("\n");
    }
    if(isscalar){
        printf("This is a scalar matrix");
    }else{
        printf("This is not a scalar matrix");
    }
}