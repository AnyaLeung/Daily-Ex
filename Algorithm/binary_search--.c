#include <stdio.h>

int binary_search(int *num, int len, int find){
    int high = 0, low = 0, middle = 0;
    high = len - 1;
    low = 0;
    middle = (high + low) / 2;

    if (num[middle]==find){
        return middle;
    }
    else{
        if(num[middle]<find){
            low = middle + 1;
        }
        if(num[middle]>find){
            high = middle - 1;
        }
        middle = (low + high) / 2;
        return binary_search(num, len/2, find);
    }
}

int main(void){
    int num[7] = {1, 2, 3, 4, 5, 6, 7};
    int len = 7, find = 5;
    int res = 0;

    res = binary_search(num, len, find);
    printf("res: %d", res);

    return 0;
}
