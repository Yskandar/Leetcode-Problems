class Solution {
public:

    bool check_letter(std::vector<std::vector<char>>& board, std::string word, int idx, int i, int j, std::vector<std::vector<bool>>& visited) {
        

        
        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0) {
            return false;
        }
        
        //cout << "idx: " << idx << endl;
        //cout << "letter: " << board[i][j] << endl;
        //cout << "visited: " << visited[i][j] << endl;
        if (board[i][j] != word[idx] || (visited[i][j])) {
            //cout << "i:" << i << " j:" << j << endl;
            return false;
        }

        if (board[i][j] == word[idx] && (idx == word.size() - 1)) {
            return true;
        }
        
        
        visited[i][j] = true;
        //cout << "setting the letter: " << board[i][j]<< " to visited: " << visited[i][j] << endl;

        if (check_letter(board, word, idx + 1, i + 1, j, visited)) { return true; };
        if (check_letter(board, word, idx + 1, i - 1, j, visited)) { return true; };
        if (check_letter(board, word, idx + 1, i, j + 1, visited)) { return true; };
        if (check_letter(board, word, idx + 1, i, j - 1, visited)) { return true; };
        visited[i][j] = false;
        return false;

    }


    bool exist(std::vector<std::vector<char>>& board, std::string word) {

        int n = board.size(), m = board[0].size();
        int idx = 0;
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                
                std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
                if (check_letter(board, word, idx, i, j, visited)) {
                    return true;
                }

            }
        }

        return false;

    }
};