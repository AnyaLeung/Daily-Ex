#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
        if(numsSize==0) return 0;

        int count = 0;
        for(int i=0; i<numsSize; i++){
            if(nums[i]!=val){
                nums[count++] = nums[i];
            }
        }
        return count;
}

int main(void){
    int arr[4] = {3, 2, 2, 3};
    
    return 0;
}
