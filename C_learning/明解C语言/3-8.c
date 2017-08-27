#include <stdio.h>

/*
	if ones place is 5
*/

int main(void)

{
	int num, ones_place;

	printf("enter an int here:");		
	scanf("%d", &num);

	if ((num % 10) == 5)  // % is higher than == so put (num % 10) 
		puts("its ones place is 5");
	else
		puts("its ones place isnt 5");

	return 0;
}
	
