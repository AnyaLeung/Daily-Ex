#include <stdio.h>
#include <string.h>

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
int main(void) {
    char mulr[1000];
    char muld[1000];
    int product[2002] = {0};
    int carry[2002] = {0}; //进位
    int last_num = 0;
    
    printf("enter multiplier here: ");
    gets(mulr);
    
    printf("enter multiplied here: ");
    gets(muld);

    memset(product,0,2002*sizeof(int)) ;   

    int lena = 0;
    int lenb = 0;
    lena = strlen(mulr);
    lenb = strlen(muld);

    
    for (int i=0; i<lena; i++) {
        for (int j=0; j<lenb; j++) {
            product[i+j+1] += ((int)muld[i]-'0') * ((int)mulr[j]-'0');
        }
    }
    
    for (int to_bit=lena+lenb; to_bit>=0; to_bit--) {
        carry[to_bit] = product[to_bit] / 10; //cal carry, save into array
        product[to_bit] -= carry[to_bit] * 10;
        product[to_bit-1] += carry[to_bit];
    }
    
    for(int m=0; m<lena+lenb; m++) {
        printf("%d", product[m]);
    }
    
    puts("\n");
    
    return 0;
}
