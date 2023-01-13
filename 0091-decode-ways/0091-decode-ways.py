class Solution:
    def numDecodings(self, s: str) -> int:
        
        n = len(s)
        if n == 1:
            return int(s != "0")
        dp_1, dp_2 = 0, 1
        if s[n-1] != "0":
            dp_1 = 1
        
        for i in range(n-2, -1, -1):
            if s[i] != "0" and float(s[i:i+2]) <= 26:
                temp = dp_1 + dp_2
                dp_2 = dp_1
                dp_1 = temp
                
            if s[i] == "0":
                dp_2 = dp_1
                dp_1 = 0
                
                
            if s[i] != "0" and float(s[i:i+2]) > 26:
                dp_2 = dp_1
                
        return dp_1
        
        