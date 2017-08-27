#include <stdio.h>

/* 设P是集合{1，2，……n-1，n}的一个全排列
 * 从排列的右端开始，找出第一个比右边数字小的数字的序号j，即j=max{i|Pi<Pi+1，i>j}
在Pj的右边的数字中，找出所有比Pj大的数字中最小的数字Pk，即k=min{i|Pi>Pj，i>j}
交换Pi，Pk
再将排列右端的递减部分Pj+1Pj+2……Pn倒转，因为j右端的数字是降序，所以只需要其左边和右边的交换，直到中间，因此可以得到一个新的排列P'=P1P2……Pj-1PkPn……Pj+2Pj+1。
*/


void nextPermutation(int* nums, int numsSize) {
    int min_index = numsSize - 1;
    int j = 0, k = 0;
    int flag = 1;
    int right_min = 0;

    for(j=numsSize-1; j>-1&&flag; j--) {
       if(nums[min_index]>nums[j]) {
            min_index = j;
            flag = 0;
       }
    }
    j++;
    right_min = j;

    for(int i=j+1; i<numsSize && !flag; i++) {
        if(nums[i]>nums[j]) {
            if(right_min==j) {
                right_min = i;j
            }
            else {
                if(nums[i]<nums[right_min]) {
                    right_min = i;
                    flag = 1;
                }
            }
        }
    }

    int tmp = 0;
    tmp = nums[j];
    nums[j] = nums[k];
    nums[k] = tmp;


    nextPermutation(nums)；
}

int main(void) {
    return 0;
}
