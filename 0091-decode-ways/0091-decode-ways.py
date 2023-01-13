class Solution:
    def numDecodings(self, s: str) -> int:
        
        n = len(s)
        if n == 1:
            return int(s != "0")
        
        dp = [0] * (n+1)
        dp[n] = 1
        if s[n-1] != "0":
            dp[n-1] = 1
        
        for i in range(n-2, -1, -1):
            if s[i] != "0" and float(s[i:i+2]) <= 26:
                dp[i] = dp[i+1] + dp[i+2]
            
            if s[i] == "0":
                dp[i] = 0
            
            if s[i] != "0" and float(s[i:i+2]) > 26:
                dp[i] = dp[i+1]
                
        return dp[0]
        
        