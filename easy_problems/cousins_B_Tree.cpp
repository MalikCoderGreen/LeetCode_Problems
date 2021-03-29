/*
993. Cousins in Binary Tree

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.

Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
*/

class Solution {
public:
    // Use Utility function to find the level of either 'x' or 'y' node.
    int getLevelUtil(TreeNode* root, int node, int lvl){
        if(!root) return 0;
        
        if(root->val == node) return lvl;
        
        int goDown = getLevelUtil(root->left, node, lvl + 1);
        
        if(goDown != 0) return goDown;
        
        goDown = getLevelUtil(root->right, node, lvl + 1);
        
        return goDown;
    }
    
    int getLevel(TreeNode* root, int node){
        return getLevelUtil(root, node, 1);
    }
    
    // Function to find parent of node.
    void findParent(TreeNode* root, int node, int& parent){
        if(!root) return;  
  
        if(root->left && root->left->val == node)
            parent = root->val;   
        
        if(root->right && root->right->val == node)
            parent = root->val;
            
        findParent(root->left, node, parent);
        findParent(root->right, node, parent);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int xParent = 0, yParent = 0;
        findParent(root, x, xParent);
        findParent(root, y, yParent);
        int xLvl = getLevel(root, x);
        int yLvl = getLevel(root, y);
        
        // Condition for nodes to be cousins; must be on the same level-
        // and have different parents.
        return (xParent != yParent && xLvl == yLvl);   
    } 
        
};
