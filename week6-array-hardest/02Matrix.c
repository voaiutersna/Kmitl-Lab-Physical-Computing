#include <stdio.h>
#include <stdbool.h>
int main(){

    double m[3][3];
    double n[3][3];
    double result[3][3];
    scanf("%lf %lf %lf", &m[0][0], &m[0][1], &m[0][2]);
    scanf("%lf %lf %lf", &m[1][0], &m[1][1], &m[1][2]);
    scanf("%lf %lf %lf", &m[2][0], &m[2][1], &m[2][2]);
    scanf("%lf %lf %lf", &n[0][0], &n[0][1], &n[0][2]);
    scanf("%lf %lf %lf", &n[1][0], &n[1][1], &n[1][2]);
    scanf("%lf %lf %lf", &n[2][0], &n[2][1], &n[2][2]);

    for(int r = 0;r<3;r++){
        for(int c = 0;c<3;c++){
            result[r][c] = 0;
            for(int k = 0;k<3;k++){
                result[r][c] += m[r][k] * n[k][c];
            }
        }
    }

    printf("A x B\n");
    for(int r = 0;r<3;r++){
        for(int c = 0;c<3;c++){
            printf("%.2lf ", result[r][c]);
        }
        printf("\n");
    }
}