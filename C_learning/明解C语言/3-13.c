#include <stdio.h>
int main(void)
{
	int a, b, c, max;

	printf("enter a here:");
	scanf("%d", &a);
	printf("enter b here:");
	scanf("%d", &b);
	printf("enter c here:");
	scanf("%d", &c);

	max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	printf("the largest one is %d \n", max);

	return 0;
}
