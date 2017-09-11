#include <stdio.h>
#define SIZE 10

void swap(int *a, int *b){
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    int a[SIZE] = {0}, b[SIZE] = {0};
    int input = 0;
    int i = 0, j = 0;
    int n = 0, m = 0;
    scanf("%d", &n);
    
    printf("enter array a[]: ");
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    
    printf("enter b[]: ");
    for(j=0; j<n; j++){
        scanf("%d", &b[j]);
    }
    
    for(m=0; m<5; m++){
        swap(&a[m], &b[m]);
    } //传入swap元素地址
    
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    
    for(j=0; j<n; j++){
        printf("%d ", b[j]);
    }
    
    return 0;
}
