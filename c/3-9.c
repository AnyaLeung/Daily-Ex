#include <stdio.h>

int main(void)
{
	int num;

	printf("enter an int here:");
	scanf("%d", &num);

	if (num == 0)
		puts("its 0");
	else if (num > 0)
		puts("its positive");
	else
		puts("its negative");

	return 0;
}
