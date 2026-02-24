# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        def findsum(root: Optional[TreeNode], n = 0) -> None:
            if not root:
                return
            n = 2 * n + root.val
            if not root.left and not root.right:
                self.ans += n
                return 
            findsum(root.left,n)
            findsum(root.right,n)
            return 
        self.ans = 0
        findsum(root)
        return self.ans
        