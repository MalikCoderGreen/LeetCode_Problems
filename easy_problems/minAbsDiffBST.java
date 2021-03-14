/*
530. Minimum Absolute Difference in BST

Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
Input:

   1
    \
     3
    /
   2

Output:
1
Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
*/
class Solution {
    // Method to collect nodes in order traversal.
    public void inOrder(TreeNode root, List<Integer> inOList){
        if(root == null) return;
        
        inOrder(root.left, inOList);
        inOList.add(root.val);
        inOrder(root.right, inOList);    
        
    }
    
    public int getMinimumDifference(TreeNode root) {
        // Create list to hold value of nodes.
        List<Integer> nodes = new ArrayList();
        // Collect nodes in order. 
        inOrder(root, nodes);
        
        // Loop through nodes list and find the minimum absolute difference.
        int minDiff = Integer.MAX_VALUE;
        for(int i = 0; i < nodes.size()-1; i++)
           minDiff = Math.min(minDiff, Math.abs(nodes.get(i+1) - nodes.get(i))); 
               
        return minDiff;
    }  
    
}
