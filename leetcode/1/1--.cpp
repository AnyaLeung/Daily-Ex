class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
     for(int i=0; i<nums.size()-1; i++){
         for(int j=i; j<nums.size(); j++){
            int sum = nums[i] + nums[j];
             if(sum==target){
                 res[0] = i;
                 res[1] = j;
                 return res;
             }
         }
     }   
    }
};
