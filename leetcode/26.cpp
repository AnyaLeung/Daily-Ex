#include <iostream>
#include <vector>
/*
 * Given a sorted array,
 * remove the duplicates in place
 * such that each element appear only once
 * return the new length.
 *
 */
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int len = nums.size();
            if(!len) return 0;

            int count = 1;       
            for(int i=0; i<len-1; i++){
                if(nums[i]!=nums[i+1]){
                    count++;
                }
                else{
                    nums.erase(i+1);
                }
            }
            return count;
        }
};
