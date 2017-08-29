/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int binary_search(int* nums, int numsSize, int target) {
    int high = numsSize - 1;
    int low = 0;
    int middle = 0, start = 0, end = 0;
    int res[2] = {0};

    while(low<=high) {
        middle = (high + low) / 2;
        if(nums[middle]==target) return middle;
        if(nums[middle]>high) low = middle + 1;
        if(nums[middle]<low) high = middle - 1;
    }
}

int binary_search_right(int* nums, int numsSize, int target) {
    int high = numsSize - 1;
    int low = 0;
    int middle = 0, start = 0, end = 0;
    int res[2] = {0};

    while(low<=high) {
        middle = (high + low) / 2;
        if(nums[middle]==target&& nums[middle+1]!=target) return middle;
        if(nums[middle]==target&& nums[middle+1]==target) low = target + 1;
        if(nums[middle]>high) low = middle + 1;
        if(nums[middle]<low) high = middle - 1;
    }
}

int binary_search_left(int* nums, int numsSize, int target) {
    int high = numsSize - 1;
    int low = 0;
    int middle = 0, start = 0, end = 0;
    int res[2] = {0};

    while(low<=high) {
        middle = (high + low) / 2;
        if(nums[middle]==target&& nums[middle-1]!=target) return middle;
        if(nums[middle]==target&& nums[middle-1]==target) high = target - 1;


        if(nums[middle]>high) low = middle + 1;
        if(nums[middle]<low) high = middle - 1;
    }
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int suchen = 0, high = 0, low = 0;
    int *left, *right;
    
    left = 
    suchen = binary_search(nums, numsSize, target);
    left = (int *)malloc(suchen * sizeof(int));
    right = (int *)malloc((numsSize - suchen -1) * sizeof(int));
    low = binary_search_left()
}
