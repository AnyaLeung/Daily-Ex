#include <stdio.h>
int main(void)
{
	int month;

	scanf("month is %d", &month);

	switch(month){
	 case 3 || 4 || 5: puts("spring");				break;
	 case 6 || 7 || 8: puts("summer");				break;
	}
	
	return 0;
} 
