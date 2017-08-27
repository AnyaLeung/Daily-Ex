#include <stdio.h>
int main(void)
{
	int no;

	printf("enter an integer plz:");
	scanf("%d", &no);
	
	if (no % 5)
		puts("this integer cant be full divided(zhengchu) by 5");

	return 0;
}
