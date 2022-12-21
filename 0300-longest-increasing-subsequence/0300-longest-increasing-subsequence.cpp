class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();
        vector<int> dp(N);
        int maxi = 1;
        dp[N - 1] = 1;

        for (int i = N - 2; i >= 0; i--) {
            dp[i] = 1;
            int curr = nums[i];

            for (int j = i + 1; j < N; j++) {
                if (curr < nums[j]){ dp[i] = max(dp[i], 1 + dp[j]); }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;

    }
};