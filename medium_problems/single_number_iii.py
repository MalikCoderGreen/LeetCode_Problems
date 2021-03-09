"""
260. Single Number III
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice, 
find the two elements that appear only once. You can return the answer in any order.

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Input: nums = [-1,0]
Output: [-1,0]

Input: nums = [0,1]
Output: [1,0]
"""
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        
        # k and l will hold single occurence numbers.
        k,l = sys.maxsize, sys.maxsize
        k_assigned = False
        # Loop will check numbers behind nums[i] and infront of nums[i] for possible duplicates.
        for i in range(len(nums)):
            # Check if the number is a single occurence and if k has been assigned already.
            if nums[i] not in nums[i+1:] and nums[i] not in nums[:i] and not k_assigned:
                k = nums[i]
                k_assigned = True
            # Once l has been found, break; no need to continue looping.
            elif nums[i] not in nums[i+1:] and nums[i] not in nums[:i] and k_assigned:
                l = nums[i]
                break
    
        return [k,l]
        
