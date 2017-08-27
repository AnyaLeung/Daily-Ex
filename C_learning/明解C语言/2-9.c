/*
	讀取兩個整數並用浮點數顯示出它們的平均值
*/

#include <stdio.h>

int main(void)
{
	int a, b;

	puts("請輸入兩個整數。");
	printf("請輸入a：");		scanf("%d", &a);
	printf("請輸入b：");		scanf("%d", &b);

	printf("它們的平均值是%f。\n", (a + b) / 2.0);  //   int / double
	// y line 12 13 with scanf %f print sth weird orz
	getchar();
	return 0;

}
