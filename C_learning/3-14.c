#include <stdio.h>

int main(void)
{
	int n1, n2, max;

	puts("enter two int plz:");
	printf("int 1:");	scanf("%d", &n1);
	printf("int 2:");	scanf("%d", &n2);

	max = (n1 > n2) ? n1:n2;

	printf("the larger one is %d\n", max);

	return 0;
}
