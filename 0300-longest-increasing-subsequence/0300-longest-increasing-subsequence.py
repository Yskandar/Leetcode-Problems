class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        
        N = len(nums)
        dp = [1] * N
        ans = 1
        
        for i in range(N-2, -1, -1):
            curr = nums[i]
            for j in range(i+1, N):
                if curr < nums[j]:
                    dp[i] = max(dp[i], 1 + dp[j])
            ans = max(ans, dp[i])
            
        return ans
        
        
        