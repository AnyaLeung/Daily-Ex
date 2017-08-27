#include <stdio.h>
int main(void)
{
    int no;

    printf("enter an int:");
    scanf("%d", &no);

    while (no >= 0)  
        printf("%d ", no--);

    printf("\n");

    return 0;
}
