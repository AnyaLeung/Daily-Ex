#include <stdio.h>

int main(void){
    double sum = 1;
    double value = 0;
    float x = 0;

    scanf("%f", &x);
    value = 1.0 / x; //

    while(value>0.000001){
        sum += value;
        value =  value * (1 / x);
    }

    printf("res: %lf", sum);
    return 0;
}
