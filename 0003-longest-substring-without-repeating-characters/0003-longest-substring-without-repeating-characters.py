class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        
        n = len(s)
        word_set = set()
        window = []
        
        max_len = 0
        
        for i in range(0,n):
            while s[i] in word_set:
                word_set.remove(window[0])
                window.pop(0)
            window.append(s[i])
            word_set.add(s[i])
            max_len = max(max_len, len(window))
        
        
        return max_len
                
            
        
        
        
        