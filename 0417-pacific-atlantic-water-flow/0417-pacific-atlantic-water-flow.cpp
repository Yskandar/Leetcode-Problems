class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        
        
        pacific, atlantic = set(), set()
        n, m = len(heights), len(heights[0])
        ans = []
        
        def dfs(r, c, curr_height, ocean_set):
            
            if r<0 or c<0 or r == n or c == m or heights[r][c] < curr_height or (r,c) in ocean_set:
                return
            
            ocean_set.add((r, c))
            dfs(r+1, c, heights[r][c], ocean_set)
            dfs(r, c+1, heights[r][c], ocean_set)
            dfs(r-1, c, heights[r][c], ocean_set)
            dfs(r, c-1, heights[r][c], ocean_set)
            
        for r in range(n):
            dfs(r, 0, heights[r][0], pacific)
            dfs(r, m-1, heights[r][m-1], atlantic)
        
        for c in range(m):
            dfs(n-1, c, heights[n-1][c], atlantic)
            dfs(0, c, heights[0][c], pacific)
        
        for r in range(n):
            for c in range(m):
                if (r,c) in pacific and (r,c) in atlantic:
                    ans.append([r,c])
        
        return ans
        
        
            
        