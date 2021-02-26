
/*
Missing Number (easy difficulty)
Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /* O(nlogn) Solution O(1) space: Runtime: ~ 20-30 ms, Best run: faster than 76.46%; Memory Usage: 18 MB. */
        // Base cases: one element. 
        if(nums.size() == 1 && nums[0] == 1)
            return 0;
        else if(nums.size() == 1 && nums[0] == 0)
            return 1;
       
        // Sort array first.
        sort(nums.begin(), nums.end());
        
        // Easiest case is when 0 is not in. Since nums is sorted, 0 should always be first element.
        if(nums[0] != 0)
            return 0;

        int jump = 0; // Variable that will determine the gap amount between elements.
        for(int i = 0; i < nums.size(); i++){
            if(i != nums.size() - 1)
                jump = nums[i+1] - nums[i];
            if(jump > 1)
                return nums[i] + 1;      
        }
    
        // We will arrive here if n itself is not present in nums.
        return nums[nums.size()-1] + 1;
        
    }
};
