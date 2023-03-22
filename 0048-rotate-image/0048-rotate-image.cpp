class Solution {
public:

    void rotate(std::vector<std::vector<int>>& matrix) {

        int n = matrix.size(), m = matrix[0].size();

        // First step is reflexion along the horizontal axis


        for (int i = 0; i < (int)n / 2; i++) {

            for (int j = 0; j < m; j++) {

                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = temp;

            }

        }
        
        // Second step is transposition
        
        for (int i = 0; i < n; i++) {

            for (int j = i+1; j < m; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }


    }


};