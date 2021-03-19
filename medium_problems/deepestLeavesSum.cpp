/*
1302. Deepest Leaves Sum

Given the root of a binary tree, return the sum of values of its deepest leaves.

Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
*/

class Solution {
public:
    
    // Function to get the maxDepth of a tree.
    int maxDepth(TreeNode* root){
        if(!root)
            return 0;
        
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        
        return max(l, r) + 1;
    }
    
    // Using the maxDepth value from maxDepth(), find out which nodes are on the level-
    // equal to the maxDepth and append them to the sum.
    void deepestLeavesUtil(TreeNode* root, int& s, int maxDepth, int currLevel){
        if(!root)
            return;
        
        // Increment the current level counter for each time we go down a level in the tree.
        currLevel++;
        deepestLeavesUtil(root->left, s, maxDepth, currLevel);
        deepestLeavesUtil(root->right, s, maxDepth, currLevel);
        
        // We have found the deepest node(s).
        if(currLevel == maxDepth)
            s += root->val;
    }
    int deepestLeavesSum(TreeNode* root) {
        if(root && !root->left && !root->right)
            return root->val;
        
        int deepSum = 0;
        int maxD = maxDepth(root);
        deepestLeavesUtil(root, deepSum, maxD, 0);
       
        
        return deepSum;
    }
};
