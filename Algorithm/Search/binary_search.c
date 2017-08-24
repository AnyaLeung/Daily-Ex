#include <stdio.h>

int binary_search(int *num, int len, int find){
    int high = 0, low = 0, middle = 0, guess = 0;
    high = len - 1;
    low = 0;
    middle = (high + low) / 2;

    while(high>low){
        guess = num[middle];
        middle = (high + low) / 2;

        if(guess==find){
            return middle; 
            //why can't return here
            //and must go to the end?
        }
        if(guess<find){
            low = middle + 1;
        }
        if(guess>find){
            high = middle - 1;
        }
    }
    return middle;

    /*
     * To write a recursion version later
     */
}

int main(void){
    int num[7] = {1, 2, 3, 4, 5, 6, 7};
    int res = 0;

    res = binary_search(num, 7, 5);
    printf("res: %d", res);

    return 0;
}
