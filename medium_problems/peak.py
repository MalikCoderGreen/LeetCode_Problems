"""
Find Peak Element (medium difficulty)
A peak element is an element that is strictly greater than its neighbors.
Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞.
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
"""

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:     
        # Base case: nothing to compare.
        if len(nums) == 1: 
            return 0        
        
        # Loop that will use x and y variables for potential neighbors.
        y = 0
        for i in range(len(nums)): 
            # Case for last element: only want to consider the neighbor before it (len(nums) - 2).
            x = nums[i-1]
            if i == len(nums)-1: 
                if nums[i] > x: 
                    return i
            
            # Case for first element: only want to consider second index of nums as neighbor. 
            elif i == 0: 
                y = nums[i+1]
                if nums[i] > y: 
                    return i
                
            # Case for all other elements in between first and last (nums[k]; 0 < k < len(nums) - 1).
            else: 
                y = nums[i+1]
                if x < nums[i] > y:
                    return i
            
            
        return -1
