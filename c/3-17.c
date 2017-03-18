#include <stdio.h>
int main(void)
{
	int month;

	puts("enter a month:");
	scanf("%d", &month);

	if (month >= 3 && month <= 5)
		printf("its spring");
	else if (month >= 6 && month <= 8)
		printf("its summer");
	else if (month == 10 || month == 11 || month == 9)
		printf("its fall");
	else if (month == 1 || month == 2 || month ==12)
		printf("its winter");
	else 
		puts("wrong num");

	return 0;
}
