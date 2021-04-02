"""
434. Number of Segments in a String

You are given a string s, return the number of segments in the string. 
A segment is defined to be a contiguous sequence of non-space characters.

Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]

Input: s = "Hello"
Output: 1
"""
class Solution:
    def countSegments(self, s: str) -> int:
        # First trim 's' of all leading and trailing
        # spaces.
        s = s.strip()
        if len(s) == 0: return 0
        if len(s) == 1: return 1 
        
        # Loop through s and append all words found.
        L = []
        i, start, = 0, 0
        while i < len(s): 
            if s[i] != " ":
                i += 1
            else:
                L.append(s[start:i])
                i += 1
                start = i
            
            # Append last word to 'L'.   
            if i == len(s) - 1:
                L.append(s[start:i+1])
                
        # Loop through 'L' and count all words not including empty values.
        final_count = 0
        for i in range(len(L)):
            if L[i] != " " and L[i] != "":
                final_count += 1
        
        return final_count
