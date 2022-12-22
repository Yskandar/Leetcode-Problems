class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        
        N1, N2 = len(text1), len(text2)
        dp = []
        for j in range(N1):
            dp += [[1]*N2]
        
        # Filling the first row and first column
        k=0
        while k < N1 and text1[k] != text2[0]:
            dp[k][0] = 0
            k+=1
        
        k=0
        while k < N2 and text2[k] != text1[0]:
            dp[0][k] = 0
            k+=1
        
        # Filling the rest
        for i in range(1, N1):
            for j in range(1, N2):
                dp[i][j] = 0
                if text1[i] == text2[j]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
                        
        return dp[N1-1][N2-1]
        