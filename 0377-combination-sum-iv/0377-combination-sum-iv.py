class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0] * (target + 1)
        dp[target] = 1
        for i in range(target-1, 0, -1):
            for num in nums:
                if i + num <= target:
                    dp[i] += dp[i + num]
        ans = 0
        for num in nums:
            if num <= target:
                ans += dp[num]
        return ans