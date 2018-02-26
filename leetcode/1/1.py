# time complexity: O(n)
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        di = {}
        for i, no in enumerate(nums):
            res_num = target - no
            if res_num in di:
                return [i, di[res_num]]
            else:
                di[no] = i
