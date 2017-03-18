#include <stdio.h>

int main(void)
{
	int a, b;

	puts("enter two int plz:");
	printf("enter a here:");
	scanf("%d", &a);
	printf("enter b here:");
	scanf("%d", &b);

	if (a > b)
		printf("the larger one is %d.\n", a);
	else
		printf("the larger one is %d.\n", b);

	return 0;
}
