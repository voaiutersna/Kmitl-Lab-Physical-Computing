#include <stdio.h>

void printFarenheit(double fahrenheit){
    printf("%.2lf f", fahrenheit);
}
void printCelcius(double celcius){
    printf("%.2lf c", celcius);
}

double celsiusToFahrenheit(double celcius){
    double result = 32 + celcius * (180.0/100.0);
    printFarenheit(result);
    return result;
}
double fahrenheitToCelcius(double fahrenheit){
    double result = ((fahrenheit - 32)*100.0)/180.0;
    printCelcius(result);
    return result;
}


int main(){

    double n;
    char c;

    scanf("%lf %c", &n,&c);
    // printf("%lf %c", n,c);
    if(c=='c' || c=='C'){
        celsiusToFahrenheit(n);
    }else{
        fahrenheitToCelcius(n);
    }

}