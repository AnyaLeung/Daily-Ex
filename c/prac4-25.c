#include <stdio.h>
int main(void)
{
    int i = 1;
    int j = 1;
    int len;

   printf("enter how many line u want here:") ;
   scanf("%d", &len);

   for (i = 1; i <= len; i ++){
       for (j = 1; j <= i - 1; j++)
            printf(" ") ;//error??
       for (j = 1; j <= (len - i) * 2 + 1; j++) {
            printf("%d", i) ;
     //  for (j = 1; j <= (len - (len - i) * 2 + 1); j++)
      //      printf(" ");
        }
        printf("\n");
   }
        return 0;
   }
