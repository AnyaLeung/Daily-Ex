#include <stdio.h>

int main(void){
    double sum = 1;
    double a = 10;
    int x = 0;
    double add = 0;
    int count = 1;

    scanf("%d", &x);
    printf("already get %d\n", x);

    while(add>0.000001){
        for(int i=1; i<=count; i++){
            add /= x;
        }
        sum += add;
    }

    printf("%lf", sum);

    return 0;
}
