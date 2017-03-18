#include <stdio.h>
int main(void)
{
    int no;

    printf("enter an int:");
    scanf("%d", &no);

    while(no-- >0)
        putchar('*');
    putchar('\n');

    return 0;
        
    }
