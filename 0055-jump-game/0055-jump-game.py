class Solution:
    def canJump(self, nums: List[int]) -> bool:
        
        n = len(nums)
        
        if n == 1:
            return True
        if nums[0] == 0:
            return False
        
        goal = n - 1
        i = n - 2 
        while i >= 0:
            if i + nums[i] >= goal:
                goal = i
            i-=1
        
        return goal == 0
        