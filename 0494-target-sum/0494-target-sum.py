class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        
        dp = dict()
        n = len(nums)
        index, total = 0, 0
        
        def recursive(index, total):
            
            if index == n:
                return int(total == target)
            if dp.get((index, total)) is not None:
                return dp[(index, total)]
            
            dp[(index, total)] = recursive(index + 1, total + nums[index]) + recursive(index + 1, total - nums[index])
            
            return dp[(index, total)]
        
        return recursive(0, 0)
            
            
        