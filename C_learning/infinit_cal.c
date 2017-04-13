#include <stdio.h>
/*
 * BASIC THOUGHT:
 * 
 *  sf the how many digits 
 *  create three such char array to save every digit
 *  cal every digit and save the result into the third array, using 强制转换
 *  while meet one digit add, remember, use if cal the next digit
 *  all cal is a while! first digit
 *  
 *  cal from right to left
 */

int sfno(char *a);
//char calc(char sub[], char bsub[], char diff[], sub_dn, bsub_dn);

int main(void) {
    char sub[1000]; //substraction
    char bsub[1000]; //be substraction
    char diff[1000]; //difference
    int sub_dn = 0;
    int bsub_dn = 0;

    sub_dn = sfno(sub); 
    bsub_dn = sfno(bsub); 
    //scanf sub and bsub with array, and know how many digits
    

    for (int i=0; i<20; i++) {
        printf("%c ", &sub[i]);
        printf("%c", &bsub[i]);
    }
    return 0;
}

int sfno(char *a) {
    char tmp;
    int digit_count=0;
    while(tmp!='\n') {
        tmp = getchar();
        if (tmp=='\b') continue;
        if (tmp<'0'||tmp>'9') continue;
        a[digit_count++] = tmp;
    }
    return digit_count;
}

char calc(char sub[], char bsub[], char diff[], int sub_dn, int bsub_dn) {
    char sign;
    int tmp = 0;
    int sub_d = 10;
    int bsub_d = 10;

    /*
    if (sub_dn<bsub_dn) {
        sign='-'; 
    }

    // >0
    for(int i=0; i<sub_dn; i++) {
       char  
    }
    */
}
