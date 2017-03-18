#include <stdio.h>
int main(void)
{
	int a, b, c;

	printf("int a:");
	scanf("%d", &a);
	printf("b:");
	scanf("%d", &b);
	printf("c:");
	scanf("%d", &c);
	
	if (a == b && b == c)
		puts("a=b=c");
	else if (b == c || a == b || c == a)
		puts("two of them are equal");
	else
		puts("they differs");

	return 0;
}
