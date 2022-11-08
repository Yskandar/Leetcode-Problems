class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        N = len(nums)
        mini = nums[0]
        maxi = nums[0]
        total_sum = nums[0]
        inter_min = nums[0]
        inter_max = nums[0]

        for i in range(1, N):
            inter_min = min(nums[i], inter_min + nums[i])
            inter_max = max(nums[i], inter_max + nums[i])
            mini = min(inter_min, mini)
            maxi = max(inter_max, maxi)
            total_sum += nums[i]

        if total_sum == mini:  # if the list only contains negative number
            return maxi
        else:  # using the fact that total = mini + maxi
            return max(maxi, total_sum - mini)
