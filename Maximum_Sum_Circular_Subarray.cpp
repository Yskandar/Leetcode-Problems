class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int inter_max = nums[0];
        int inter_min = nums[0];
        int maxi = nums[0];
        int mini = nums[0];
        int total_sum = nums[0];
        const int& N = nums.size();

        for (int i = 1; i < N; i++) {
            inter_max = max(nums[i], inter_max + nums[i]);
            inter_min = min(nums[i], inter_min + nums[i]);
            total_sum += nums[i];
            maxi = max(maxi, inter_max);
            mini = min(mini, inter_min);

        }

        if (total_sum == mini) { return maxi; }
        else { return max(maxi, total_sum - mini); }



    }
};
