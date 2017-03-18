/*
	读取两个整数， 并求它们的平均值
*/

#include <stdio.h>

int main(void)
{

	int a, b;

	printf("enter a here:");	scanf("%d", &a);
	printf("enter b here:");	scanf("%d", &b);

	printf("average = %d", (a + b) / 2);

	return 0;
}
