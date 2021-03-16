/*
654. Maximum Binary Tree

You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.

Input: nums = [3,2,1]
Output: [3,null,2,null,1]
*/

class Solution {
public:
    // Recursive function to build left and right subtrees. 
    // Args: (n: list of nodes, l: beginning index of subarr, r: ending index of subarr)
    // Return: root to max binary tree.
    TreeNode* buildMaxRec(vector<int>& n, int l, int r){
        if(l == r)
            return nullptr;
        
       
        int maxNode = -1, maxPos;
        // Find max node value and the position of the max.
        for(int i = l; i < r; i++){
            std::cout << n[i] << " ";
            if(maxNode < n[i]){
                maxNode = n[i];
                maxPos = i;
            } 
        }
   
        TreeNode* root = new TreeNode(maxNode);
     
        // Recursively build left and right subtrees.
        root->left = buildMaxRec(n, l, maxPos);
        root->right = buildMaxRec(n, maxPos+1, r);
        
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {    
        return buildMaxRec(nums, 0, nums.size());      
    }
};
