#include <stdio.h>
int main(void)
{
	int num;

	printf("enter an int:");	scanf("%d", &num);

	if (num >= 0)
		printf("abs is %d\n", num);
	else
		printf("abs is %d\a\n", -num);

	return 0;
}


