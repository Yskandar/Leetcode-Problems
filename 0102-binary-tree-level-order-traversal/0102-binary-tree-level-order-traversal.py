# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        
        dico_level = {}
        
        def traverse(root, dico_level, level):
            
            
            if root:
                
                if dico_level.get(level) is None:
                    dico_level[level] = [root.val]
                else:
                    dico_level[level].append(root.val)
            
                traverse(root.left, dico_level, level+1)
                traverse(root.right, dico_level, level+1)
        
        traverse(root, dico_level, 0)
        return list(dico_level.values())
            
        