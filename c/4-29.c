//畫一個直角在右下角的等腰直角三角形
#include <stdio.h>
int main(void)
{
    int i, j, len;
    printf("短邊:");
    scanf("%d", &len);
    
    for (i = 1; i <= len; i ++) {
        for (j = 1; j <= len - i; j++) {
            putchar(' ') ;
        }
        for (j = 1; j <= i; j++) {  //len是定值，都是i
            putchar('*') ;
        }
        putchar('\n');
    }
    return 0;
}
