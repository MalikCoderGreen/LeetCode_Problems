/*

653. Two Sum IV - Input is a BST

Given the root of a Binary Search Tree and a target number k, 
return true if there exist two elements in the BST such that their sum is equal to the given target.

Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
*/

class Solution {
public:
    // Use in-order traversal to store nodes in list.
    // Args: root: root of tree; n: vector for nodes
    // Return: None
    void inOrder(TreeNode* root, vector<int> &n){
        if(!root) return;
        
        inOrder(root->left, n);
        n.push_back(root->val);
        inOrder(root->right, n);
    }
    bool findTarget(TreeNode* root, int k) {     
        // Vector will hold the nodes of the tree in order.
        vector<int> nodes;
        inOrder(root, nodes);
        
        // Loop through beginning and end of list to find a possible match.
        int i = 0, j = nodes.size()-1;
        while(i != j){
            if(nodes[i] + nodes[j] < k) i++;
                
            else if(nodes[i] + nodes[j] > k) j--;      
            
            else return true;
        }
        
        return false;  
    }
};
