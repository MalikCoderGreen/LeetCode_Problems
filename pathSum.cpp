/*
112. Path Sum

Given the root of a binary tree and an integer targetSum, 
return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true

Input: root = [1,2,3], targetSum = 5
Output: false

Input: root = [1,2], targetSum = 0
Output: false
*/
class Solution {
public:
    
    // Use pre order traversal to look through all the nodes and-
    // Find all sums to leaf nodes.
    void preOrder(TreeNode* root, int s, int tar, bool& found){
        if(!root) return;
                  
        s += root->val;
        
        // Only set 'found = true' if the target is equal and we ended on a leaf node.
        if(s == tar && root && !root->left && !root->right)
            found = true;
        
        preOrder(root->left, s, tar, found);
        preOrder(root->right, s, tar, found);
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        bool found = false;
        preOrder(root, 0, targetSum, found);
        
        return found;
    }
};
