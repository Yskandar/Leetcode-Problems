# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        
        
        def dfs_count(root, count):
            
            if root is None:
                return count
            
            return max(dfs_count(root.right, count+1), dfs_count(root.left, count+1))
        
        
        return dfs_count(root, 0)
        