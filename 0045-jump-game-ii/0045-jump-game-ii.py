class Solution:
    def jump(self, nums: List[int]) -> int:
        
        n = len(nums)
        dp = [0]*n
        
        for i in range(n-2, -1, -1):
            mini = float('inf')
            for j in range(i+1, min(i+nums[i]+1, n)):
                mini = min(mini, dp[j])
            dp[i] = 1 + mini
        
        return dp[0]
            
            
        