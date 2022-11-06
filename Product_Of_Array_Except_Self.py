class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        N = len(nums)

        ans = N*[1]
        pre = N*[1]
        suff = N*[1]
        pre[0] = nums[0]
        suff[N-1] = nums[N-1]
        for i in range(1, N-1):
            pre[i] = pre[i-1] * nums[i]
            suff[N-1 - i] = suff[N-i] * nums[N-1-i]
        for i in range(1, N-1):
            ans[i] = pre[i-1]*suff[i+1]
        ans[0] = suff[1]
        ans[N-1] = pre[N-2]

        return ans
