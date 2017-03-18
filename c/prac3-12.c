#include <stdio.h>
int main(void)
{
    int no;

    printf("enter an int plz:");    scanf("%d", &no);

	switch(no % 2){
	 case 1 : puts("odd num");		break;
	 case 2 : puts("even num");		break;
	}

	return 0;
}
