#include <stdio.h>
int main(void)
{
	int a = 37;
	int b = 28;
	int sum = 0;
//	int retry; retry not necessary only when u wanna user 2 choose goon
	int m = b;

	do{		
		sum = sum + m;
		m = m + 1;
	  }while (m <= a);

	printf("their sum is %d\n", sum);
	return 0;
}
