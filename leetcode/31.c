#include <stdio.h>

/* 设P是集合{1，2，……n-1，n}的一个全排列
 * 从排列的右端开始，找出第一个比右边数字小的数字的序号j，即j=max{i|Pi<Pi+1，i>j}
 在Pj的右边的数字中，找出所有比Pj大的数字中最小的数字Pk，即k=min{i|Pi>Pj，i>j}
 交换Pj，Pk
 再将排列右端的递减部分Pj+1Pj+2……Pn倒转，因为j右端的数字是降序，所以只需要其左边和右边的交换，直到中间，因此可以得到一个新的排列P'=P1P2……Pj-1PkPn……Pj+2Pj+1。
 */


void nextPermutation(int nums[10], int numsSize) {
        if(numsSize==1) return ;
        if(numsSize==2) {
                int tmp = nums[0];
                nums[0] = nums[1];
                nums[1] = tmp;
            return ;
            }
    
    int count = 0;
    for(int i=0; i<numsSize-1; i++) {
        if(nums[i]>=nums[i+1]) {
            count++;
        }
    }
    if(count==numsSize-1) {
        int *p = nums;
        int *q = &nums[numsSize-1];
        int tmp = 0;
        while(p<q) {
            tmp = *p;
            *p = *q;
            *q = tmp;
            p++;
            q--;
        }
    } // 3 2 1 --> 1 2 3
    else { // not descending order
        
        int flag = 1, j = 0;
        int right_min_index = 0;
        
        for(int i=numsSize-2; i>-1 && flag; i--) {
            if(nums[i]<nums[i+1]) {
                flag = 0;
                j = i;
            }
        }
        
        for(int m=j; m<numsSize; m++) {
            if(nums[m]>nums[j]) {
                if(!right_min_index) {
                    right_min_index = m;
                }
                else {
                    if(nums[m]<=nums[right_min_index]) {
                        right_min_index = m;
                    }
                }
            }
        }
        
        int tmp = nums[j];
        nums[j] = nums[right_min_index];
        nums[right_min_index] = tmp;
        
        int *p = &nums[j+1];
        int *q = &nums[numsSize-1];
        
        while(p<q) {
            tmp = *p;
            *p = *q;
            *q = tmp;
            p++;
            q--;
        }
    }
}

/*
int main(void) {
    int test[2] = {1, 2};
    int numsSize = 2;
    nextPermutation(test, numsSize);
    for(int i=0; i<numsSize; i++) {
        printf("%d ", test[i]);
        printf("\n");
    }
    
    return 0;
}
*/
