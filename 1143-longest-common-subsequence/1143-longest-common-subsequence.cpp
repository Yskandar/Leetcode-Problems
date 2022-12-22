class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        // Initializing DP array
        const int N1 = text1.size();
        const int N2 = text2.size();
        vector<vector<int>> dp(N1, vector<int> (N2,1));

        // Filling first row and first column
        int k = 0;
        while (k < N1 && text1[k] != text2[0]) {
            dp[k][0] = 0;
            k++;
        }

        k = 0;
        while (k < N2 && text2[k] != text1[0]) {
            dp[0][k] = 0;
            k++;
        }

        // Filling the rest
        for (int i = 1; i < N1; i++) {
            for (int j = 1; j < N2; j++) {

                if (text1[i] == text2[j]) { dp[i][j] = 1 + dp[i - 1][j - 1]; }
                else { dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); }

            }

        }
        return dp[N1 - 1][N2 - 1];
    }
};