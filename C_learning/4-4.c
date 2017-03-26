#include <stdio.h>
int main(void)
{ 	
	int sum = 0;
	int cnt = 0;
	int retry;

	do {
		int n;
	
		printf("enter an int plz:");
		scanf("%d", &n);

		sum += n;  //sum = sum + n;
		cnt ++ ;

       printf("do u wanna continue?  <Yes...0/No...9>");
       scanf("%d", &retry);

        } while (retry == 0);
        
        printf("sum is %d, ave is %.2f.\n", sum, (double)sum / cnt); 
        
        return 0;
}
