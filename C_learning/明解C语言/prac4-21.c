#include <stdio.h>
int main(void)
{
    int i,j;
    int a = 0;
    int b = 0;

    printf("enter an int here:");
    scanf("%d", &i);
    printf("enter another int here:");
    scanf("%d", &j);


    i = (a > b)? (i = a):(i = b);//longer
    j = (a > b)? (j = b):(j = a);

    for (a = 0; a < i; a++){
        for (b = 0; b < j; b++){
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}
//T T
