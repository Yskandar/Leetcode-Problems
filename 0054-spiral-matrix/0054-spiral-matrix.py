class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        
        def return_spiral(inter_mat, n_start, m_start, n_end, m_end):
            ans = []

            i = n_start
            j = m_start
            
            if m_start == m_end-1 and n_start == n_end-1:
                return [inter_mat[n_start][m_start]]
            
            if m_start == m_end-1:
                return[inter_mat[i][m_start] for i in range(n_start, n_end)]
            
            if n_start == n_end-1:
                return inter_mat[n_start][m_start: m_end]

            while j < m_end-1:
                ans.append(inter_mat[i][j])
                j+=1


            while i < n_end-1:
                ans.append(inter_mat[i][j])
                i+=1

            while j > m_start:
                ans.append(inter_mat[i][j])
                j-=1

            while i > n_start:
                ans.append(inter_mat[i][j])
                i-=1
            return ans
    
        n, m = len(matrix), len(matrix[0])
        ans = []
        i, j = 0, 0
        while (n-1 >= i and m-1 >= j):
            #print(i,j,n,m)
            ans += return_spiral(matrix, i, j, n, m)
            i+=1
            j+=1
            n-=1
            m-=1
        return ans
        
        
        
    
    