"""
Plus one
Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

Input: digits = [9,9,9]
Output: [1,0,0,0]
Explanation: The array represents the integer 1000.
"""

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:  
        # Case where last digit is not equal to 9; no need to create extra space.
        if digits[len(digits) - 1] != 9:
            digits[len(digits) - 1] += 1
            return digits
        
        # Edge cases for digits that have 9 as the last value in list.
        else:
            change = 0
            for i in range(len(digits)): 
                if digits[i] == 9:
                    change += 1
            
            # The entire list consists of 9s; need to allocate +1 space.
            if change == len(digits): 
                digits = [0 for x in range(change+1)]
                digits[0] = 1
                return digits
            
            # If digits[k] == 9, we need to turn it to 0.
            # Keep looping until we find digits[k] != 9 and then add 1 to that value.
            else:
                k = len(digits) - 1
                while digits[k] == 9:
                    digits[k] = 0
                    k -= 1
                digits[k] += 1
        
                return digits
