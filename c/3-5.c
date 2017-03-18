#include <stdio.h>

int main(void)
{
	int num;

	printf("enter an int plz:");
	scanf("%d", &num);

	if (num)
		puts("this int isnt 0");
	else
		puts("this int is 0");

	return 0;
}
