#include <stdio.h>

#define NUMBER 80

int main(void){
    int num;
    int i = 0;
    int mark[NUMBER];
    int count[11] = 0;

    printf("請輸入學生人數：");

    do{
        scanf("%d", &num) ;
        if (num < 1 || num > NUMBER){
            printf("\a, 請輸入1~%d的數字", NUMBER) ;
        }
    }while(num < 1 || num > NUMBER)

   printf("請輸入%d個人的分數：", num);

   printf("%d號：");
   scanf("%d", &mark[NUMBER]);

   count[mark[NUMBER]/10]++;

   putchar('\n---分布圖---');
   printf("  100");

   for (j = 0; j < count[10]; j++){
       putchar('*') ;
   }
      
   for (s = 9; s >= 0; s--){
        printf("%d~%d", s * 10, s * 10 + 9) ;
        for (d = 9; d < count[9]; d--){
            putchar("*") ;
        }
   }
   putchar('\n');
   return 0;
}
