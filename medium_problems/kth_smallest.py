"""
Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.
Input: root = [3,1,4,null,2], k = 1
Output: 1
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def getNodes(self, root: TreeNode, nodes: List[int]): 
        """
        Append nodes to list using inorder traversal.
        
        Args:
            root (root of tree), nodes (list of treenodes)
        """    
        if not root:
            return 
        
        self.getNodes(root.left, nodes)
        nodes.append(root.val)
        self.getNodes(root.right, nodes)
                         
        
    def kthSmallest(self, root: TreeNode, k: int) -> int: 
        nodes = []
        self.getNodes(root, nodes)
        
        # Problem specifies 1-indexed; return k-1 for the value.
        return nodes[k-1]
