class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        # Initialize dp array
        N = len(s)
        dp = [False] * (N+1)
        dp[N] = True
        
        
        # fill dp array
        for i in range(N-1, -1, -1):
            
            for word in wordDict:
                if i + len(word) > N:
                    continue
                elif s[i:i + len(word)] == word and dp[i + len(word)]:
                    dp[i] = True
                    break
        return dp[0]
                
                    
            
            
        