#include <stdio.h>
int main(void)
{
    int retry;

    do{
    
         int i = 0;
         int num;

         do{
             printf("enter an num here:") ;
             scanf("%d", &num);
            
             if (num <= 0) {
                 printf("do not enter <= 0, plz,enter again:") ;
                 scanf("%d", &num);
             }
         }while (num <= 0);
   
         for (i = 0; i <num; i++){
             putchar('*') ;
         }
          putchar('\n');

         printf("u wanna go on? [Yes...1/No...0]");
         scanf("%d", &retry);
    }while (retry == 1);

    return 0;
}
