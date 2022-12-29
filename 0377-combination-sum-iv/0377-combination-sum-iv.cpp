class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        vector<unsigned int> dp(target + 1, 0);
        dp[target] = 1;
        for (int i = target - 1; i > 0; i--) {

            for (int num : nums) {
                if (num + i <= target) { dp[i] += dp[i + num]; }

            }

        }
        int ans = 0;
        for (int num : nums) {
            if (num <= target) { ans += dp[num]; }
        }

        return ans;
    }
};