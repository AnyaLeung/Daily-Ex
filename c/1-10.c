/*
	對兩個代碼進行初始化並顯示
*/
#include <stdio.h>

int main(void)
{
	int vx = 57;			/*vx是int型的變量，初始化爲57*/
	int vy = vx + 10;	/*vy是int型的變量，初始化爲vx + 10*/

	printf("vx的值是%d。 \n", vx);
	printf("vy的值是%d。 \n", vy);

	getchar();
	return 0;
}
