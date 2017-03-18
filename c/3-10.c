#include <stdio.h>

/*
	if int is positive, judge its even or not
*/

int main(void)
{
	int num;

	printf("enter an int here:");
	scanf("%d", &num);

	if (num > 0)
		if (num % 2)
			puts("its even num");
		else
			puts("its odd num");
	else
		puts("ur num is not positive \a\n");
	
	return 0;
}
