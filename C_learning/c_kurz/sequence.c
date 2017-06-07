#include <stdio.h>

int main(void){
    int a = 1, b = 2, tmp = 0;
    int i = 0;
    float res = 0;
    float sum = 0;

    for(; i<20; i++){
        res = (float)a / (float)b;
        sum += res;
        tmp = b;
        b += a; 
        a = tmp;
    }
    printf("result is: %f", sum);

    return 0;
}
