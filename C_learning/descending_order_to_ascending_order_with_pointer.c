#include <stdio.h>

int main(void) {
    int test[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    int *p = test;
    int *q = &test[9];
    int tmp = 0;
    
    while(p<=q) {
        tmp = *p;
        *p = *q;
        *q = tmp;
        p++;
        q--;
    }
    
    for(int i=0; i<10; i++) {
        printf("%d ", test[i]);
    }
    return 0;
}
