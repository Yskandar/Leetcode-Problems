class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int gain = nums[0];
        int mini = nums[0];
        int N = nums.size();
        vector<int> sum_list(N);
        sum_list[0] = nums[0];

        for (int i = 1; i < N; i++) {

            sum_list[i] = sum_list[i - 1] + nums[i];
            int test = max(gain, max(sum_list[i] - mini, sum_list[i]));
            gain = test;
            if (mini > sum_list[i]) { mini = sum_list[i]; }


        }
        return gain;

    }
};
