/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
Input: root = [1,null,2,3]
Output: [1,3,2]
*/


class Solution {
public:
    
    /*
    *   Helper function to append nodes to vector by reference.
    *   Args: root (root of tree), nodes: (vector of ints)
    */
    void inOrderTSub(TreeNode *root, vector<int> &nodes){
        if(!root)
            return;
           
        inOrderTSub(root->left, nodes);
        nodes.push_back(root->val);
        inOrderTSub(root->right, nodes);    
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        
        vector<int> inOrderNodes;
        inOrderTSub(root, inOrderNodes);
        
        return inOrderNodes;
              
    }
};
