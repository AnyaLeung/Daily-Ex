#include <stdio.h>
int main(void)
{
    int i = 0; 
    int n = 1;
    int num;

    scanf("%d", &num);

    for (i = 1; n <=num; i++){
        printf("%d", i) ;
        n++;

        if (i == 9){
            i = -1; 
        }
    }
    putchar('\n');
    return 0;
}
