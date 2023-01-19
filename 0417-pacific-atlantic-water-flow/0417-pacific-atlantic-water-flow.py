class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        
        n, m = len(heights), len(heights[0])
        dico_pacific = {}
        dico_atlantic = {}
        dico_flow = {}
        dico_visited_atlantic = {}
        dico_visited_pacific = {}

        
        # First pass
        for i in range(n):
            for j in range(m):
                h = heights[i][j]
                dico_flow[(i,j)] = []

                # Filling the flow
                if i+1 < n and heights[i+1][j] <= h:
                    dico_flow[(i,j)] += [(i+1, j)]
                if i-1 >= 0 and heights[i-1][j] <= h:
                    dico_flow[(i,j)] += [(i-1, j)]
                if j+1 < m and heights[i][j+1] <= h:
                    dico_flow[(i,j)] += [(i, j+1)]
                if j-1 >= 0 and heights[i][j-1] <= h:
                    dico_flow[(i,j)] += [(i, j-1)]

                # Near the ocean ?
                if i==n-1 or j==m-1:
                    dico_atlantic[(i,j)] = True
                if i==0 or j==0:
                    dico_pacific[(i,j)] = True


        # Now filling the paciifc and atlantic dicos

        def dfs_pacific(cell):

            if dico_pacific.get(cell) == True:
                return True
            if dico_pacific.get(cell) == False:
                return False
            if dico_visited_pacific.get(cell) == True:
                return False

            dico_visited_pacific[cell] = True
            for next_cell in dico_flow[cell]:
                if dfs_pacific(next_cell):
                    dico_pacific[cell] = True
                    return True
            #dico_pacific[cell] = False
            dico_visited_pacific[cell] = False
            return False

        def dfs_atlantic(cell):
            if dico_atlantic.get(cell) == True:
                return True
            if dico_atlantic.get(cell) == False:
                return False
            if dico_visited_atlantic.get(cell) == True:
                return False

            dico_visited_atlantic[cell] = True
            for next_cell in dico_flow[cell]:
                if dfs_atlantic(next_cell):
                    dico_atlantic[cell] = True
                    return True
            dico_visited_atlantic[cell] = False
            #dico_atlantic[cell] = False
            return False

        ans = []
        for i in range(n):
            for j in range(m):
                cell = (i,j)
                dico_visited_atlantic = {}
                dico_visited_pacific = {}
                if dfs_atlantic(cell) and dfs_pacific(cell):
                    ans += [[i,j]]
        return ans
        
        
            
        