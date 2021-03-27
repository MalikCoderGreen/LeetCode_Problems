/*

1800. Maximum Ascending Subarray Sum

Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

A subarray is defined as a contiguous sequence of numbers in an array.
A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi < numsi+1. Note that a subarray of size 1 is ascending.

Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.

Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.

*/

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        // Keep track of the maximum sum and the current sum in 'nums'.
        int max_sub_sum = -1, curr_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            // This check is for every value except for the last.
            if(i < nums.size() - 1){
                if(nums[i] < nums[i+1])
                    curr_sum += nums[i];
                
                // This means nums[i+1] < nums[i] so we need to get nums[i]-
                // before we restart the sum.
                else{
                    curr_sum += nums[i];
                    max_sub_sum = std::max(max_sub_sum, curr_sum);
                    curr_sum = 0;
                }
            }
            
            // If the last element is greater than the second to last, then-
            // we need to incoportate that in the last possible curr_sum.
            else{
               if(nums[i] > nums[i-1])
                    curr_sum += nums[i];
            }
        }
   
        return std::max(max_sub_sum, curr_sum);
        
    }
};
