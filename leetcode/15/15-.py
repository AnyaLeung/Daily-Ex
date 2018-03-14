#沒寫完的 O(n^2)的3sum
class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        a = 0
        val = {}
        size = len(nums)
        res = [[[0 for x in range(size)] for j in range(size)] for i in range(size)]
        
        while a < size:
            b = a + 1
            while b < size:
                sum = nums[a] + nums[b] #sum value
                val[sum] = [nums[a],nums[b]] 
                #print("a b sum ", nums[a], nums[b], sum)
                b += 1
            a += 1 
        #save all value and index into {value:[index1, index2]}
        #ok
        
        c,count = 0, 0
        while c < size:
            no = nums[c]
            #print("no ", no, "   ")
            print(val.keys())
            if val.get(-no):
                tmp = []
                tmp.append(nums[c])
                tmp += val[no]
                
                res[count] = tmp
                count += 1                
            c += 1
        
        return res
