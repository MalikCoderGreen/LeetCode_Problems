"""
112. Path Sum
Given the root of a binary tree and an integer targetSum, 
return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
A leaf is a node with no children.

Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
"""


class Solution:

    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:  
        if not root:
            return   
        if root and not root.left and not root.right:
            return root.val == targetSum

        # Global switch will change to True inside dfs if target sum is found.
        global sum_found
        sum_found = False

        # Use param "s" to keep track of the recursive path sum for each path down to a leaf.
        def dfs(root, s):
            if not root:
                return
            if root and not root.left and not root.right:
                s += root.val
                if s == targetSum:
                    global sum_found
                    sum_found = True

            dfs(root.left, s + root.val)
            dfs(root.right, s + root.val)
        
        dfs(root, 0)
     
        return sum_found
