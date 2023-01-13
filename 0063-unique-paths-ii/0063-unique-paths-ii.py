class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        
        if obstacleGrid[-1][-1] == 1 or obstacleGrid[0][0]:
            return 0
        
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = []
        for i in range(m):
            dp += [[0]*n]
        
        dp[-1][-1] = 1
        k=n-1
        while k >=0 and obstacleGrid[-1][k] != 1:
            dp[-1][k] = 1
            k-=1
        k=m-1
        while k>=0 and obstacleGrid[k][-1] != 1:
            dp[k][-1] = 1
            k-=1
            
            
        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                if obstacleGrid[i][j] != 1:
                    dp[i][j] = dp[i+1][j] + dp[i][j+1]
        
        return dp[0][0]