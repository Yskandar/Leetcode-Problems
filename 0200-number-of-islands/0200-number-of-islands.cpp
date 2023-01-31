class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (grid[i][j] == '0') { continue; }
                if (visited[i][j]) { continue; }

                visited[i][j] = true;
                vector<pair<int, int>> queue;
                
                queue.push_back({i, j});


                while (not queue.empty()) {
                    int i_curr = queue.back().first, j_curr = queue.back().second;
                    //cout << "I fail here1" << endl;
                    visited[i_curr][j_curr] = true;
                    queue.pop_back();
                    //cout << i_curr << endl;
                    //cout << j_curr << endl;
                    if (i_curr < n - 1 && grid[i_curr + 1][j_curr] == '1' && not visited[i_curr + 1][j_curr]) { queue.push_back({i_curr + 1, j_curr}); }
                    if (i_curr > 0 && grid[i_curr - 1][j_curr] == '1' && not visited[i_curr - 1][j_curr]) { queue.push_back({ i_curr - 1, j_curr }); }
                    if (j_curr < m - 1 && grid[i_curr][j_curr + 1] == '1' && not visited[i_curr][j_curr+1]) { queue.push_back({ i_curr, j_curr + 1 }); }
                    if (j_curr > 0 && grid[i_curr][j_curr - 1] == '1' && not visited[i_curr][j_curr]-1) { queue.push_back({ i_curr, j_curr - 1 }); }

                }
                count += 1;


            }


        }
        return count;
    }
};