class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        if ((obstacleGrid[m - 1][n - 1] == 1) || (obstacleGrid[0][0] == 1)) { return 0; }

        vector<vector<unsigned int>> dp(m, vector<unsigned int>(n, 0));
        dp[m - 1][n - 1] = 1;
        int k = n - 2;
        while (k >= 0 && (obstacleGrid[m - 1][k] != 1)) { 
            dp[m - 1][k] = 1;
            k -= 1;
        }
        k = m - 2;
        while (k >= 0 && (obstacleGrid[k][n-1] != 1)) {
            dp[k][n-1] = 1;
            k -= 1;
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (obstacleGrid[i][j] != 1) { dp[i][j] = dp[i + 1][j] + dp[i][j + 1]; }
            }

        }

        return dp[0][0];

    }
};