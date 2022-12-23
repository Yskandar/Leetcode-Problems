class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        // Initializing the DP array
        const int N1 = text1.size();
        const int N2 = text2.size();
        vector<vector<int>> dp(N1 + 1, vector<int> (N2 + 1, 0));

        // Filling the DP array
        for (int i = 1; i <= N1; i++) {
            for (int j = 1; j <= N2; j++) {

                if (text1[i-1] == text2[j-1]) { dp[i][j] = 1 + dp[i - 1][j - 1]; }
                else { dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); }
                
            }

        }
        return dp[N1][N2];
    }
};