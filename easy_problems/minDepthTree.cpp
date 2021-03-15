/*
111. Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

Input: root = [3,9,20,null,null,15,7]
Output: 2

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
*/

class Solution {
public:

    int minDepth(TreeNode* root) {
        // Base case.
        if(!root) return 0; 
        
        // Traverse left and right children.
        int lCount = minDepth(root->left);
        int rCount = minDepth(root->right);
        
        // Cases if on a path, no children are found.
        if(lCount == 0) return rCount+1;
        else if(rCount == 0) return lCount+1;
        
        return std::min(lCount, rCount) + 1;
        
    }
};
