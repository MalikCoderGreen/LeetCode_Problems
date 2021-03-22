/*

114. Flatten Binary Tree to Linked List

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Input: root = []
Output: []

*/

class Solution {
public:
    
    // Use preorder traversal to get all nodes and append to vector.
    void preOrder(TreeNode* root, vector<int>& n){
        if(!root) return;
        
        n.push_back(root->val);
        preOrder(root->left, n);
        preOrder(root->right, n);
        
    }
    
    void flatten(TreeNode* root) {
        if(!root) return;
        
        vector<int> nodes;
        preOrder(root, nodes);
        TreeNode* cursor = root;
        
        // Use this loop to 'flatten' the tree; set all -
        // node->right = new tmp node.
        for(int i = 1; i < nodes.size(); i++){
            TreeNode* tmp = new TreeNode(nodes[i]);
            cursor->left = nullptr;
            cursor->right = tmp;
            cursor = cursor->right;
        }
        
    }
};
