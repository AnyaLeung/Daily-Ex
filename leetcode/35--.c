#include <stdio.h>

int binary_search(int* nums, int numsSize, int target) {
    int high = numsSize - 1;
    int low = 0;
    int middle = (high + low) / 2;

    while(low<=high) {
        int value = nums[middle];

        if(value==target) return middle;
        if(value<target) low = middle + 1;
        if(value>target) high = middle - 1;
        middle = (high + low) / 2;
    }
    return middle;
}

int judge_and_return(int *nums, int numsSize, int target, int res) {
    if(res==0) {
        if(nums[res]<=target) return res;
        else {
            return 1;
        }
    }

    if(nums[res]==numsSize-1)) {
        if(nums[res]>=target) return res;
        else {
            return nums-2;
        }
    }

    if((nums[res]>target)&& (nums[res-1]<target)) {
        return res;
    }

    if(nums[res]<target) return res+1;
    if(nums[res]>target) return res-1;
}

int searchInsert(int* nums, int numsSize, int target) {
    if(!numsSize||numsSize==1) return 0;
    int res = -1;

    res = binary_search(nums, numsSize, target);
    if(nums[res]==target) return res;
    else {
        judge_and_return(nums, numsSize, target);

    }
    
    return res;
}

int main(void) {
    int nums[5] = {1, 2, 3, 6, 7};
    int res = 0;

    res = binary_search(nums, 5, 4);
    printf("%d", res);
    return 0;
}
