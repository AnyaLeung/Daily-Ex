int* twoSum(int* nums, int numsSize, int target) {
    int i = 0, j = 0;
    int* res;
    bool flag = 1;
    for(i=0; i<numsSize&& flag; i++){
        for(j=0; j<numsSize&& flag; j++){
            if(j!=i&& (nums[i]+nums[j]==target)){
                flag = 0;
            }
        }
    }
    res = (int *)malloc(sizeof(int) * 2);
    res[0] = i - 1;
    res[1] = j - 1;
    return res;
}
