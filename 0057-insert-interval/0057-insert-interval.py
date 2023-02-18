class Solution:
    
    def overlapping(self, interval1, interval2):
        
        return not (interval2[0] > interval1[1] or interval2[1] < interval1[0])
    
    def merge(self, interval1, interval2):
        
        #if interval2[0] > interval1[0] and interval2[1] < interval1[1]:
        #    return interval1
        #if interval2[0] < interval1[0] and interval2[1] > interval1[1]:
        #    return interval2
        
        start, end  = None, None
        
        start = min(interval1[0], interval2[0])
        end = max(interval1[1], interval2[1])
        
        return [start, end]
    
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        if len(intervals) == 0:
            return [newInterval]
        start, end = newInterval
        
        
        
        if end < intervals[0][0]:
            return [newInterval] + intervals
        if start > intervals[-1][1]:
            return intervals + [newInterval]
        
        
        # Deal with overlapping first interval and overlapping last
        
        
        i = 0
        while i < len(intervals) and start > intervals[i][0]:
            i+=1
        
        if i-1>=0 and self.overlapping(intervals[i-1], newInterval):
            temp = intervals.pop(i-1)
            return self.insert(intervals, self.merge(temp, newInterval))
        
        if i < len(intervals) and self.overlapping(intervals[i], newInterval):
            temp = intervals.pop(i)
            return self.insert(intervals, self.merge(temp, newInterval))
        
        else:
            return intervals[:i] + [newInterval] + intervals[i:]
            
        