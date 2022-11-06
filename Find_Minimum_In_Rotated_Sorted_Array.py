class Solution:
    def findMin(self, nums: List[int]) -> int:
        N = len(nums)

        left_idx = 0
        right_idx = N -1 

        if nums[left_idx] < nums[right_idx]:
            return nums[left_idx]
        if N ==2:
            return nums[right_idx]

        while left_idx != right_idx:
            mid_idx = ((right_idx - left_idx) // 2) + left_idx

            if nums[mid_idx -1]> nums[mid_idx]:
                return nums[mid_idx]
            if nums[mid_idx] > nums[mid_idx +1]:
                return nums[mid_idx +1]

            if nums[mid_idx] > nums[left_idx]:
                left_idx = mid_idx +1

            elif nums[mid_idx] < nums[left_idx]:
                right_idx = mid_idx -1
        return nums[left_idx]
