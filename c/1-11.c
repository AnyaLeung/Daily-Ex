/*
	顯示並確認輸入的整數值
*/

#include <stdio.h>
int main(void)
{
	int no;

	printf("請輸入一個整數：");
	scanf("%d", &no);
	
	printf("您輸入的是：%d。 \n", no);
	
	return 0;
}
