#include <stdio.h>
int main(void)
{
    int a;
    int i = 2;
    
    printf("enter int here:");
    scanf("%d", &a);

    while (i <= a){
        printf("%d ", i);
        i = i + 2;
    }

    printf("\n");
    return 0; 
}
