#include <stdio.h>
int main(void)
{
    int i = 0;
    int no;
    
    scanf("%d", &no);

    while (no>0){
        no /= 10;
        i = i + 1;
    }    
    
    printf("%d \n", i);

    return 0;
}
