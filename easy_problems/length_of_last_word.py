"""
58. Length of Last Word

Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.
A word is a maximal substring consisting of non-space characters only.

Input: s = "Hello World"
Output: 5

Input: s = " "
Output: 0

"""
class Solution:
    def lengthOfLastWord(self, s: str) -> int: 
        # Remove trailing and leading white spaces.
        s = s.strip()
            
        count = 0
        j = len(s) - 1
        # Scan from the back to the front and stop after we-
        # count all the letters of the last word.
        while j >= 0 and s[j] != ' ':
            j -= 1
            count += 1     
        
        return count
