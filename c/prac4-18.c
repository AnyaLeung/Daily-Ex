#include <stdio.h>
int main(void)
{
    int i = 0;
    int num;

    printf("how many *:");
    scanf("%d", &num);

    for(i = 0; i < num; i ++)
    {
        printf("*");
        
        while(i % 5 == 0){
            printf("\n");
        }
    } 
    
   return 0;
} 
