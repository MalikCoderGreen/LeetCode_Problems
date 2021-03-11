/*
485. Max Consecutive Ones
Given a binary array, find the maximum number of consecutive 1s in this array.

Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
The maximum number of consecutive 1s is 3.
*/

class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        // Continuously compute the current max and previous max.
        int maxCount = 0, prevMax = 0, count = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 1) count++;
            
            else{
                prevMax = count;
                maxCount = Math.max(maxCount, prevMax);
                count = 0;
            } 
        }
        
        // Possible max (count) that was never assigned to maxCount.
        return Math.max(maxCount, count);     
    }
}
