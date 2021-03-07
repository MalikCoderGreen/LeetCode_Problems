"""
34.Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Input: nums = [], target = 0
Output: [-1,-1]
"""
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:      
        # Ensure that if positions are not found, -1 and -1 will be returned regardless.
        start, end = -1, -1
        for i in range(len(nums)): 
            # Cases for if start hasn't been assigned and if it has.
            if nums[i] == target and start < 0:
                start = i
                end = i         
            elif nums[i] == target and start >= 0:
                end = i 

        return [start,end]
