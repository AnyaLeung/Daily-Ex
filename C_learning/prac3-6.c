#include <stdio.h>

int main(void)
{
	int a, b, c, max;

	printf("a:");	scanf("%d", &a);
	printf("b:");	scanf("%d", &b);
	printf("c:");	scanf("%d", &c);	
	
	max = a;
	if (b > max) 	max = b;
	if (c > max)	max = c;

/*	if (a > b)		max = a;
	if (c > max)	max = c;
*/
// cannot write like this cuz max didnt initialize

	printf("the largest one is %d\n", max);

	return 0;
}
