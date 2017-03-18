#include <stdio.h>

int main(void)
{
    int a, b, max;

    puts("enter two int plz:");
    printf("enter a here:");
    scanf("%d", &a);
    printf("enter b here:");
    scanf("%d", &b);

    if (a > b)
		max = a;
	else if (b > a)
		max = b;
    
	printf("the larger one is %d.\n", max);
    
return 0;
}
