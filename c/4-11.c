#include <stdio.h>
int main(void)
{
    int i,no;

    printf("enter an int");
    scanf("%d", &no);

    for (i = 0; i <= no; i++)//i++ before
        printf("%d", i);
    putchar('\n');

    return 0;
}
