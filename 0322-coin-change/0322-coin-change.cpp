class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Using dynamic programming, we solve iteratively for target starting at 0 to amount
        // Initializing the dp array
        vector<int> dp(amount + 1);
        dp[0] = 0;
        
        // solving iteratively
        for (int target = 1; target <= amount; target++) {

            dp[target] = INT_MAX; // set initial value to INF            
            
            // for each coin, substract it to the target and check if already know how to reach that new amount
            for (auto coin : coins) {
                if (target - coin < 0) { continue; } // can't substract below 0
                else if (dp[target - coin] != INT_MAX) { dp[target] = min(dp[target], dp[target - coin] + 1); } // if a fixed number of coin exists to sum up to that new amount, use it
            }
        }

        if (dp[amount] == INT_MAX) { return -1; }
        else { return dp[amount]; }
    }
};