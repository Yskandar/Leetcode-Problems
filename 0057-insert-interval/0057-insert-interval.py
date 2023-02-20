class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        
        ans = []
        
        
        for i in range(len(intervals)):
            start, end = newInterval
            if start > intervals[i][1]:
                ans.append(intervals[i])
            
            elif end < intervals[i][0]:
                ans = ans + [newInterval] + intervals[i:]
                return ans
            
            else:
                newInterval = [min(start, intervals[i][0]), max(end, intervals[i][1])]
            
        ans.append(newInterval)
        
        return ans