class Solution:
    def countSubstrings(self, s: str) -> int:
        
        
        
        count = 0
        n = len(s)
        # Looking for palindromic centers
        
        
        for i in range(0, len(s)):
            j = 0
            while i-j >= 0 and i+j < n and s[i-j] == s[i+j]:
                count += 1
                j += 1
                
        for i in range(0, len(s)-1):
            j = 0
            if s[i] != s[i+1]:
                continue
            else:
                while i-j >= 0 and i+j+1 < n and s[i-j] == s[i+j+1]:
                    count+=1
                    j+=1
        
        return count
                
            
        
        
        
        
        
        
        