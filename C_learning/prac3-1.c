#include <stdio.h>

int main(void)
{
	int a, b;
	
	printf("enter two integer plz:\n");
	printf("enter A here:");		scanf("%d", &a);
	printf("enter B here:");		scanf("%d", &b);

	if (a % b)
		puts("B isnt divisor of A");

	else
		puts("B is divisor of A ");

	return 0;
}
