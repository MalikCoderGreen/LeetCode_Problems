/*
747. Largest Number At Least Twice of Others

You are given an integer array nums where the largest integer is unique.

Determine whether the largest element in the array is at least twice as much as every other number in the array. 
If it is, return the index of the largest element, or return -1 otherwise.

Input: nums = [3,6,1,0]
Output: 1
Explanation: 6 is the largest integer.
For every other number in the array x, 6 is at least twice as big as x.
The index of value 6 is 1, so we return 1.
*/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxPos = -1;
        int max = 0;
        int atLeast = 0; // Needs to be n-1 in order to return 'maxPos'.
       
        // Obtain the max position (O(n)).
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max){
                max = nums[i];
                maxPos = i;
            }
        }
        // Sort the list (O(nlog(n))).
        std::sort(nums.begin(), nums.end());
        // Find the total value of 'atLeast' (O(n)).
        for(int i: nums){ 
            if(i != max && i * 2 <= max)   
                atLeast++;   
        }
       
        if(atLeast != nums.size() - 1) return -1;
        
        return maxPos;   
    }
};
