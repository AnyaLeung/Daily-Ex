#include <stdio.h>
int main(void)
{
    int  n;
    int i = 0;

    puts("enter");
    scanf("%d", &n);

    while(i < n){
        printf("*\n");
        ++i;
    }
    
    putchar('\n');
    return 0;
}
