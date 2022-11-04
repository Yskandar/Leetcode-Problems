class Solution:
    def search(self, nums: List[int], target: int) -> int:
        N = len(nums)
        left = 0
        right = N - 1 
        while left <= right:
            mid = (left + right)//2
            if nums[mid] == target:
                return mid
            if nums[left] == target:
                return left
            if nums[right] == target:
                return right

            if nums[mid]>=nums[left] and target < nums[left]:
                left = mid +1
            elif nums[mid]>=nums[left] and target > nums[mid]:
                left = mid +1
            elif nums[mid]>=nums[left] and target < nums[mid]:
                right = mid -1

            elif  nums[mid]<=nums[left] and target > nums[left]:
                right = mid -1
            elif  nums[mid]<=nums[left] and target < nums[mid]:
                right = mid -1
            elif nums[mid]<=nums[left] and target > nums[mid]:
                left = mid +1
        
        return -1
