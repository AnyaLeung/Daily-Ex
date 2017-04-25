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
    } //error while out of range 1000-9999

    while(input_no) {
        split[i] = input_no % 10;
        input_no /= 10;
        i++;
    } //split input_no into bit

    printf("reverse number is: ");
    for(int i=0; i<4; i++) {
        printf("%d", split[i]);
    } //print bit number reversely

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
    } //bubble sort, small->large

    printf("the smallest number can produce is: ");
    for(int f=0; f<4; f++) {
        printf("%d", split[f]);
    }

    printf("\n");

    printf("the largest number can produce is: ");
    for(int p=3; p>=0; p--) {
        printf("%d", split[p]);
    }

    printf("\n");

    return 0;
}
