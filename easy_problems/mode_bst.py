"""
501. Find Mode in Binary Search Tree

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.

Input: root = [1,null,2,2]
Output: [2]

Input: root = [0]
Output: [0]
"""
class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        if not root: return []
        
        # Use in order traversal and append nodes to dictionary to-
        # obtain their frequency in the tree.
        def inOrderT(root, l): 
            if not root: return
            
            inOrderT(root.left, l)
            
            if root.val in l.keys(): l[root.val] += 1
            else: l[root.val] = 1
                
            inOrderT(root.right, l)
            
        
        l = {} 
        inOrderT(root, l)
        
        # Obtain the max value from the map.
        max_val = max(l.values())
        
        # Return a list of all nodes that have the max value.
        return [ node for node in l if l[node] == max_val]
