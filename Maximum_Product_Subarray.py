class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        N = len(nums)
        maxi = nums[0]
        inter_max = nums[0]  # keeping track of the minimum product
        inter_min = nums[0]  # keeping track of the maximum product
        for i in range(1, N):
            inter_max, inter_min = max(nums[i], nums[i]*inter_max, nums[i]*inter_min), min(nums[i], nums[i]*inter_min, nums[i]*inter_max)
            maxi = max(inter_max, maxi)


        return maxi
