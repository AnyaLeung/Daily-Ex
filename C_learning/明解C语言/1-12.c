/*
	讀取一個整數並顯示其5 倍數的值
*/
#include <stdio.h>
int main(void)
{
	int no;

	printf("請輸入一個整數：");  //print('enter ur num here:')
	scanf("%d", &no); /*讀取整數值*/  //a = input()

	printf("這個數的五倍是：%d", no * 5);  //print('a * 5 = ', a * 5)
	getchar();
	getchar();
	return 0;
}
