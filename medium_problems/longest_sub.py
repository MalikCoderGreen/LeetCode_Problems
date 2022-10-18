"""
3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0

        words = {} # Map to hold the value of all unique subtrings from 's'
        i, j = 0, 0
        sub = "" # hold value of current substring
        while i < len(s):
            if s[i] in sub:
                words[sub] = len(sub)
                j += 1
                i = j
                sub = s[j:i+1]       

            else:
                sub += s[i]
            
            i += 1

        if len(sub) > 0:
            words[sub] = len(sub)   

        # Get max length substring from map and return
        return words[max(words, key=words.get)]
