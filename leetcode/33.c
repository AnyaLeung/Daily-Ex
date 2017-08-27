#include <stdio.h>
#include <string.h>

int search(int* nums, int numsSize, int target) {
    int high = numsSize - 1;
    int low = 0;
    int middle = (high + low) /2;
    int target_index = 0;
    int flag = 1;

    while(low<high && flag){
        if(nums[middle]==target) {
            target_index = middle;
            flag = 0;
            if(nums[middle]<target) low = middle + 1;
            else high = middle - 1;
        }
    }
    if(flag) return -1;
    else{
        int *p = nums;
        int *tmp;
        int i = 0;
        for(i=0; i<target_index; i++){
            tmp[i] = nums[i];
        }
        printf("i: %d\n", i);

        for(; i<numsSize; i++){
            nums[i-target_index] = nums[i];
        }

        for(i=0; i<target_index; i++){
            nums[target_index+i] = tmp[i];
        }
    }
    return target_index;
}

int main(void){
    int nums[7] = {0, 1, 2, 3, 4, 5, 6};
    int res = 0;
    res = search(nums, 7, 4);
    printf("res: %d\n", res);

    return 0;
}
