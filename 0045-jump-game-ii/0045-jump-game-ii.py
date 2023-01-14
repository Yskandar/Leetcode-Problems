class Solution:
    def jump(self, nums: List[int]) -> int:
        
        n = len(nums)
        res = 0
        l = r = 0
        while r < n-1:
            temp = r
            for j in range(l, r+1):
                r = max(r, j + nums[j])
            l = temp + 1
            res += 1    
        
        return res
            
            
        