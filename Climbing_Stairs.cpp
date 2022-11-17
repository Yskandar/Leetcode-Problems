class Solution {
public:
    int climbStairs(int n) {
        
        int n_2 = 0;
        int n_1 = 1;
      
        // Dynamic programming : dp[n] = dp[n-1] + dp[n-2]
        for (int i=0; i<n; i++){
            int temp = n_2;
            n_2 = n_1;
            n_1 = n_1 + temp;
        }
        return n_1;
    }
};
