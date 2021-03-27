/*

872. Leaf-Similar Trees

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true

Input: root1 = [1], root2 = [1]
Output: true

Input: root1 = [1], root2 = [2]
Output: false

Input: root1 = [1,2], root2 = [2,2]
Output: true

*/

class Solution {
public: 
    
    // Append leaves to each vector for both roots.
    void appendLeaves(TreeNode* root, vector<int>& leaves){
        if(!root) return;
        
        if(!root->left && !root->right)
            leaves.push_back(root->val);
        
        appendLeaves(root->left, leaves);
        appendLeaves(root->right, leaves);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        appendLeaves(root1, v1);
        appendLeaves(root2, v2);
        
        return v1 == v2;
    }
};
