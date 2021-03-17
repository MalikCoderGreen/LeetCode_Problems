/*
671. Second Minimum Node In a Binary Tree

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. 
If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. 
More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
If no such second minimum value exists, output -1 instead.

Input: root = [2,2,5,null,null,5,7]
Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
*/
class Solution {
public:
    
    // Brute force gather all nodes.
    void findSecMinR(TreeNode* root, std::vector<int>& n){
        if(!root)
            return;
             
        findSecMinR(root->left, n);
        n.push_back(root->val);
        findSecMinR(root->right, n);    
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        if(root && !root->left && !root->right)
            return -1;
        
        // Create vector of nodes.
        std::vector<int> nodes;
        
        // Gather nodes from tree and sort.
        findSecMinR(root, nodes);  
        std::sort(nodes.begin(), nodes.end());
        
        // Loop to find second minimum.
        for(int i = 0; i < nodes.size(); i++)
            if(nodes[i+1] > nodes[i]) return nodes[i+1];
                    
        return -1;
    }
};
