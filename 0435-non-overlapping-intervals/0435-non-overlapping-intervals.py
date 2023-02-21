class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        
        # first sort the list of intervals
        
        intervals.sort(key = lambda x:x[0])
        
            
        count = 0
        prev = intervals[0]
        k = 0
        
        while k <len(intervals) - 1:
            curr = intervals[k + 1]
            
            if prev[1] > curr[0]:
                count += 1
                if prev[1] > curr[1]:
                    prev = curr
            
            else:
                prev = curr
            
            k+=1
            
        return count