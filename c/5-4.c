/*为double[7]的数组的全部元素赋值0.0*/
#include <stdio.h>
int main(void)
{
    int i = 0;
    double v[7];

    for (i = 0; i < 7; i++){
        v[i] = 0.0;
    }

    for (i = 0; i < 7; i++){
        printf("v[%d] = %.1f", i, 0.0) ;
        printf("\n");
    }
    return 0;
}
