#include <stdio.h>
#include <stdlib.h>
/*
 * Given a sorted array,
 * remove the duplicates in place
 * such that each element appear only once
 * return the new length.
 *
 */

int removeDuplicates(int* nums, int numsSize) {
    if(numsSize==0) return;

    int count = 1;
    if(numsSize==0) return 
    for(int i=0; i<numsSize-1; i++){
        if(nums[i]!=nums[i+1]){
            count++;
        }
    }
    return count;
} //no need to judge the first, must be unique

int main(void){
    int arr[0] = {1, 1, 1, 4, 5, 5, 6, 8, 9, 10};
    int res = 0;
    res = removeDuplicates(arr, 10);
    printf("result: %d", res);
    return 0;
}
