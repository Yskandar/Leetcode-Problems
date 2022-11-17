class Solution:
    def climbStairs(self, n: int) -> int:
        n_2 = 0
        n_1 = 1
        # Dynamic programming : dp[n] = dp[n-1] + dp[n-2]
        for i in range(n):
            n_1, n_2 = n_1 + n_2, n_1
        return n_1
