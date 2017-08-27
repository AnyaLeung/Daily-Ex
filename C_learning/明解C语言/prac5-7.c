#include <stdio.h>

#define m 4

int main(void){
    int i = 0;
    int v[m] ;
    int num;

    printf("數據個數:");
    scanf("%d", &num) ;

    for (i = 0; i < m; i++){
        printf("%d號：", i + 1);
        scanf("%d", &v[i]);
    }
    return 0;
}
