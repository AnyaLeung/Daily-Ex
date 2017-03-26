#include <stdio.h>
int main(void)
{
	int retry;

	do {
		int no;

		printf("enter an int:");
		scanf("%d", &no);

		if	(no % 2)
			puts("this is an odd num");
		else
			puts("its an even num");

		printf("wanna again? [Yes...0 / No...9]:");
		scanf("%d", &retry);
	}	while(retry == 0);

	return 0;
}
