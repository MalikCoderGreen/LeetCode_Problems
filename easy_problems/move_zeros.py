"""
Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
"""
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Two pointer approach. 
        # Only swap when we encounter non-zero values.
        j = 0
        for i in range(len(nums)): 
            if nums[i] != 0: 
                nums[i], nums[j] = nums[j], nums[i]
                j += 1
              
