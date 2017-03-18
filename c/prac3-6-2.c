#include <stdio.h>

int main(void)
{
	int a, b, c, max;

	printf("a:");	scanf("%d", &a);
	printf("b:");	scanf("%d", &b);
	printf("c:");	scanf("%d", &c);

	max = a;
	max = (max > b)? max : b;
	max = (max > c)? max : c;

	printf("largest one %d\n", max);

	return 0;
}
