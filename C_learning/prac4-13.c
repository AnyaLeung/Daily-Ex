#include <stdio.h>
int main(void)
{
    int i = 0;
    int sum = 0;
    int num, tmp;

    printf("how many num u wanna get?\n");
    scanf("%d", &num);

    for(i = 0; i < num; i ++) {
        printf("No.%d: ",i + 1 );
        scanf("%d", &tmp);
        sum += tmp;
    }

    printf("sum is %d.\n", sum);
    
    return 0;
    }
