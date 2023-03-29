# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
    
        if p is None and q is None:
            return True
        
        if p and q is None or p is None and q or p.val != q.val:
            return False
        
            
        return self.isSameTree(p.right, q.right) and self.isSameTree(p.left, q.left)
        
        
            
        