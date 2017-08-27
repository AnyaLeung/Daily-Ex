//畫一個直角在左下角的等腰直角三角形吧~

#include <stdio.h>
int main(void)
{
    int i, j, len;
    printf("短邊: ");
    scanf("%d", &len);

    for (i = 1; i <= len; i ++){
        for (j = 1; j <= i; j++) {
            putchar('*') ;
        }
            putchar('\n');
    }
    return 0;
}
