#include <stdio.h>

int main(void) {
    int input_no = 0;
    int split[4] = {10};
    int i = 0;
    int order[4] = {10};
    int tmp = 0;

    printf("enter a number between 1000 and 9999: ");

    scanf("%d", &input_no); 

    while(input_no<1000||input_no>9999) {
        printf("invalid input, enter your number again:");
        scanf("%d", &input_no);
    } //不在范围内的时候报错

    while(input_no) {
        split[i] = input_no % 10;
        input_no /= 10;
        i++;
    } //将该数字拆分成位，存在数组里

    printf("reverse number is: ");
    for(int i=0; i<4; i++) {
        printf("%d", split[i]);
    } //反序打印数组里的数字

    printf("\n");

    for(int m=1; m<4; m++) {
        for(int n=0; n<4-m; n++) {
            if(split[n]>split[n+1]) 
            {
                tmp = split[n];
                split[n] = split[n+1];
                split[n+1] = tmp;
            }
        }
    } //冒泡排序，降序

    printf("the smallest number can produce is: ");
    for(int f=0; f<4; f++) {
        printf("%d", split[f]);
    }//打印排序后的数组，从大到小，从而构建“最大数字”

    printf("\n");

    printf("the largest number can produce is: ");
    for(int p=3; p>=0; p--) {
        printf("%d", split[p]);
    }//反序打印，构建最小数字

    printf("\n");

    return 0;
}
