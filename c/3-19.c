/*
	switch statement
*/

#include <stdio.h>

int main(void)
{
	int no;

	printf("enter num here:");
	scanf("%d", &no);

	switch(no % 3){
	 case 0 : puts("can be divided by 3");	break;
	 case 1 : puts("no % 3 = 1");			break;
	 case 2 : puts("no % 3 = 2");			break;
}
	return 0;
}
