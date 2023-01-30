
class Solution {

public:


    void dfs(int r, int c, int curr_height, vector<vector<int>>& heights, vector<vector<bool>>& ocean_set) {
        int n = heights.size(), m = heights[0].size();
        vector<int> pair = { r,c };
        if (r<0 or c<0 or r==n or c==m or ocean_set[r][c] or heights[r][c] < curr_height) {
            return;
        }

        ocean_set[r][c] = true;
        dfs(r + 1, c, heights[r][c], heights, ocean_set);
        dfs(r - 1, c, heights[r][c], heights, ocean_set);
        dfs(r, c + 1, heights[r][c], heights, ocean_set);
        dfs(r, c - 1, heights[r][c], heights, ocean_set);

    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        for (int c = 0; c < m; c++) {
            dfs(0, c, heights[0][c], heights, pacific);
            dfs(n-1, c, heights[n-1][c], heights, atlantic);
        }
        for (int r = 0; r < n; r++) {
            dfs(r, 0, heights[r][0], heights, pacific);
            dfs(r, m - 1, heights[r][m - 1], heights, atlantic);
        }
        
        vector<vector<int>> ans;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                vector<int> pair = { r,c };
                if (pacific[r][c] and atlantic[r][c]) {
                    ans.push_back(pair);
                }


            }

        }
        return ans;

    }


};