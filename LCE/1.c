#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    int i = 0, j = 0;
    int* res;
    res = (int*)malloc(2 * sizeof(int));
    for(i=0; i<numsSize-1; i++){
        for(j=i+1; j<numsSize; j++){
            if(nums[i]+nums[j]==target){
                res[0] = i;
                res[1] = j;
                return res; 
                //为啥这句不写就不对啊。。
            }
        }
    }
    return res;
}

int main(void){
    int nums[4] = {1, 2, 3, 4};
    int* res;
    res = twoSum(nums, 4, 7);
    for(int i=0; i<2; i++){
        printf("%d ", res[i]);
    }
    return 0;
}
