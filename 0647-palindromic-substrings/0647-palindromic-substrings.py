class Solution:
    def countSubstrings(self, s: str) -> int:
        
        count = 0
        n = len(s)
        
        # Looking for palindromic centers of odd length palindromes
        for i in range(0, len(s)):
            j = 0
            k = 0
            while i-j >= 0 and i+j < n and s[i-j] == s[i+j]:
                count += 1
                j += 1
            
            while i-k >= 0 and i+k+1 < n and s[i] == s[i+1] and s[i-k] == s[i+k+1]:
                count += 1
                k+=1
        
        return count
                
            
        
        
        
        
        
        
        