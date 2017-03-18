#include <stdio.h>

int main(void)
{
    int no;

    printf("plz enter an int >0:");
    scanf("%d", &no);

    while (no >= 0 )  {
        printf("%d ", no);
        no--;
    }
    printf("\n");

    return 0;
}
