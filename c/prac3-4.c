#include <stdio.h>

int main(void)
{
	int a, b;

	printf("enter two int here:\n");
	printf("enter a here:");	scanf("%d", &a);
	printf("enter b here:");	scanf("%d", &b);


	if (a == b)
		puts("a equal with b");
	else
		if (a > b)
			puts("a is larger than b");
		else
			puts("b is larger than a");

	return 0;
}
