/*
287. Find the Duplicate Number
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.

Input: nums = [1,3,4,2,2]
Output: 2

Input: nums = [1,1]
Output: 1

Input: nums = [1,1,2]
Output: 1
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // First sort vector.
        sort(nums.begin(), nums.end());
        // Scan array and look for duplicate where the duplicate numbers have to be adjacent.
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == nums[i+1])
                return nums[i];
        }
    }
};
