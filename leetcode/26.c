#include <stdio.h>

/*
 * Given a sorted array, 
 * remove the duplicates in place 
 * such that each element appear only once.
 *
 * Return the new length.
 */

int removeDuplicates(int* nums, int numsSize) {
    if(!numsSize) return 0;

    int count = 1;
    for(int i=1; i<numsSize; i++){
        if(!(nums[i]==nums[count-1])){
            nums[count] = nums[i];
            count++;
        }
    }
    return count;
}

