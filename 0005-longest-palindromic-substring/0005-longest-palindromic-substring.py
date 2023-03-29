class Solution:
    def longestPalindrome(self, s: str) -> str:
        
        ans = s[0]
        max_len = 1
        n = len(s)
        for i in range(0, len(s)):
            j = 0
            k = 0
            while i-j>=0 and i+j<n and s[i-j] == s[i+j]:
                if max_len < 2*j +1:
                    max_len = 2*j + 1
                    ans = s[i-j:i+j+1]
                j+=1
                
            
            while i-k >= 0 and i+1+k < n and s[i] == s[i+1] and s[i-k] == s[i+k+1]:
                if max_len < 2*k + 2:
                    max_len = 2*k + 2
                    ans = s[i-k:i+2+k]
                k+=1
                
                
        
        return ans
        
                
            
            
            
        