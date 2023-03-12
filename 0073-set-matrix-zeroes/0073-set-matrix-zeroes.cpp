class Solution {
public:

	void setZeroes(std::vector<std::vector<int>>& matrix) {

		int n = matrix.size(), m = matrix[0].size();

		std::vector<std::vector<int>> indices = {};

		for (int i = 0; i < n; i++) {

			for (int j = 0; j < m; j++) {

				if (matrix[i][j] == 0) {
					indices.push_back({ i,j });
				}


			}


		}


		for (int idx = 0; idx < indices.size(); idx++) {
			int i = indices[idx][0], j = indices[idx][1];

			matrix[i] = std::vector<int>(m, 0);
			for (int row = 0; row < n; row++) {
				
                if(row != i){matrix[row][j] = 0;}
			}

		}


	}




};