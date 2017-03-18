/*
	whether integer u can be divided by 5..
*/

#include <stdio.h>

int main(void)

{
	int no;
	
	printf("enter an integer plz:");
	scanf("%d", &no);

	if (no % 5)
		puts("cannot be divided by 5");
	
	else
		puts("can be divided by 5");

	return 0;
}
