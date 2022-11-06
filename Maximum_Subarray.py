class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        # Not using Kadane's algorithm:
        gain = nums[0]
        mini = nums[0]
        N = len(nums)
        sum_list = N*[nums[0]]
        
        for i in range(1, N):
            sum_list[i] = sum_list[i-1] + nums[i]

            gain = max(sum_list[i] - mini, gain, sum_list[i])

            if sum_list[i] < mini:
                mini = sum_list[i]

        
        return gain
