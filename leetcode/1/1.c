//O(n^2)
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
