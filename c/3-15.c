#include <stdio.h>

int main(void)
{
	int a, b;

	printf("2 int:");

	printf("a:");	
	scanf("%d", &a);
	printf("b:");
	scanf("%d", &b);

	printf("their difference (?) is %d. \n", (a > b)? a - b:b - a);

	return 0;
}
