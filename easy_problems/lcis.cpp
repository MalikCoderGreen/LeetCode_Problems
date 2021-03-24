/*

674. Longest Continuous Increasing Subsequence

Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). 
The subsequence must be strictly increasing.

A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1],
..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].


Input: nums = [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5] with length 3.
Even though [1,3,5,7] is an increasing subsequence, it is not continuous as elements 5 and 7 are separated by element
4.

*/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0) 
            return 0;
        
        // Keep track of the current LCIS and the maxLCIS so far.
        int currLCIS = 1, maxLCIS = 0;
        // Loop through and add value to current LCIS length if i < i+1.
        for(int i = 0; i < nums.size(); i++){
            if(i < nums.size() - 1 && nums[i] < nums[i+1])
                currLCIS += 1;
            
            else{ 
                maxLCIS = std::max(currLCIS, maxLCIS);
                currLCIS = 1;
            }
        }
        
        return maxLCIS;
    }
};
