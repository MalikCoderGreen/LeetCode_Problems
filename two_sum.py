"""
Two Sum II - Input array is sorted (easy difficulty)
Given an array of integers numbers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.
You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

Input: numbers = [2,3,4], target = 6
Output: [1,3]

Input: numbers = [-1,0], target = -1
Output: [1,2]
"""
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # Define start and end variables. 
        j = 0
        k = len(numbers) - 1
        
        # Want to scan through and check from both sides closing on a potential match. 
        # From the condition, we know we cannot return and element plus itself; that is where this loop ends.
        # The fact that this array is sorted allows us to use these conditionals to check for a match.
        while j != k:
            # If we know our sum is less than the target, move j up.
            if numbers[j] + numbers[k] < target: 
                j += 1
            # Other wise we are greater and need to move k down.
            elif numbers[j] + numbers[k] > target: 
                k -= 1
            # Found it.
            else:
                return [j+1, k+1]
        
 
        return -1
