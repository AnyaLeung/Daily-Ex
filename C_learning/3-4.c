#include <stdio.h>
int main(void)
{
	int no;

	printf("enter an int plz:");	scanf("%d", &no);
	
	if (no % 2)
		puts("its an odd num(jishu)");
	else
		puts("its an even num(oushu)");

	return 0;
}
