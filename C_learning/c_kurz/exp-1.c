#include <stdio.h>

int main(void){
    short int no[4] = {0};
    unsigned int num[4] = {0};
    unsigned int max = 0, min = 0;
    int i = 0;

    printf("enter four short integer here: ");
    scanf("%hd %hd %hd %hd", &no[0], &no[1], &no[2], &no[3]);

    for(i=0; i<4; i++){
        num[i] = (unsigned)no[i];
        //  printf("%u and ", num[i]);
    }

    max = (unsigned)num[0]; 
    min = (unsigned)num[0];

    for(i=0; i<4; i++){
        if(num[i]>max) max = num[i];
        if(num[i]<min) min = num[i];
    }
    
    printf("The difference is: %u", max - min);

    return 0;
}
