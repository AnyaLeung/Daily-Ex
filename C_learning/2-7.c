/*
	讀取兩個實數值， 並用實屬顯示它們的和、差、積、商
*/

#include <stdio.h>

int main(void)
{
	double vx, vy;
	
	puts("請輸入兩個數：");
	printf("實數vx:");	scanf("%1f", &vx);
	printf("實數vy:");	scanf("%1f", &vy);

	printf("和爲%f", vx + vy);
	printf("差爲%f", vx - vy);
	printf("積爲%f", vx * vy);
	printf("商爲%f", vx / vy);

	return 0;
}
