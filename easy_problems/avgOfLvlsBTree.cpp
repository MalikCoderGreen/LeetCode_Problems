/*
637. Average of Levels in Binary Tree

Given the root of a binary tree, 
return the average value of the nodes on each level in the form of an array. 
Answers within 10-5 of the actual answer will be accepted.

Input: root = [3,9,20,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
*/
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        // Nodes will process all nodes at the current level.
        queue<TreeNode*> nodes;
        vector<double> lvlAvgs;
        
        // Loop through all levels and accumulate sum of all nodes on each level using-
        // inner for loop. After the for loop is over, divide the sum by the # of nodes-
        // on the level.
        nodes.push(root);
        while(!nodes.empty()){
            
            int lvlSz = nodes.size();
            double lvlSum = 0;
            for(int i = 0; i < lvlSz; i++){
                TreeNode* currNode = nodes.front();
                nodes.pop();
                
                lvlSum += currNode->val;
                
                // Process next nodes for the queue.
                if(currNode->left) nodes.push(currNode->left);
                if(currNode->right) nodes.push(currNode->right);
            }
            
            // Level average calculation.
            lvlSum /= lvlSz;
            lvlAvgs.push_back(lvlSum);
        }
        
        return lvlAvgs;
        
    }
};
