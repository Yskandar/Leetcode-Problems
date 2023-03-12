class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n, m = len(matrix), len(matrix[0])
        list_indices = []
        
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    list_indices.append((i,j))
  
        for pair in list_indices:
            i, j = pair
            matrix[i] = [0]*m
            for row in range(n):
                matrix[row][j] = 0
        
        return matrix