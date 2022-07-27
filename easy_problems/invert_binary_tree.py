'''
226. Invert Binary Tree
Given the root of a binary tree, invert the tree, and return its root.

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root
 
        q = []
        q.append(root)
        while(len(q) != 0):
            node = q.pop(0)
            
            # Node has both children
            if node.right and node.left:
                tmp = node.right
                node.right = node.left
                node.left = tmp
                q.append(node.left)
                q.append(node.right)
            
            # Node has only left child
            elif node.left and not node.right:
                node.right = node.left
                node.left = None
                q.append(node.right)
            
            # Node has only right child
            elif node.right and not node.left:
                node.left = node.right
                node.right = None
                q.append(node.left)
            
        return root
