/* two_func,c -- 一個文件中包含兩個函數*/
# include <stdio.h>
void butler(void);
int main(void)
{
	printf("I will summon the butler function. \n");
	butler();
	printf("Yes, bring me some tea n writeable DVDs.  \n");

		return 0;
}
void butler(void) /*函數定義開始*/
{
	printf("You rang, sir? \n");
	getchar();
}

/*結尾加 `;` !!!*/
