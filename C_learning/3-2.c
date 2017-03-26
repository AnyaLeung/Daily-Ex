/*
	is the int 13579...
*/

#include <stdio.h>

int main(void)
{
	int no;

	printf("enter an int plz:");
	scanf("%d", &no);

	if (no% 2)
		puts("the int u enter is 13579...");

	return 0;
}
