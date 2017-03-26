/*
	整數與浮點數
*/

#include <stdio.h>

int main(void)
{
	int n;	//integer
	double x;	//float

	n = 9.99;
	x = 9.99;

	printf("int 型變量n 的值： %d\n", n);	//9
	printf("			  n / 2： %d\n ", n / 2);		//  9/2

	printf("double 型變量x 的值： %f\n", x);	//9.99
	printf("			      x /2.0  ：%f\n", x / 2.0);		//9.99/2.0

	/*
		double類型的顯示使用%f
	*/
	getchar();
	return 0;
}
