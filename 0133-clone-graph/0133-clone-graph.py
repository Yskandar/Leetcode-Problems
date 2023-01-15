"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        
        if node is None:
            return None
        
        
        dico_node = dict()
        queue = [node]
        visited = []
        
        while queue:
            curr = queue.pop(0)
            
            if curr not in visited:
                node_copy = Node(curr.val)
                dico_node[curr.val] = node_copy
                queue += curr.neighbors
                visited.append(curr)
                
        # Second round
        
        for curr in visited:
            val = curr.val
            neighbors = curr.neighbors
 
            for neighbor_node in neighbors:
                if dico_node[val].neighbors is not None:
                    dico_node[val].neighbors.append(dico_node[neighbor_node.val])
                else:
                    dico_node[val].neighbors = [dico_node[neighbor_node.val]]
                    
        
        return dico_node[node.val]