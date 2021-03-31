"""
151. Reverse Words in a String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.

"""
class Solution:
    def reverseWords(self, s: str) -> str: 
        # Count spaces before anything.
        # If there are no spaces at all, nothing to reverse
        # becasue 's' is one word.
        space_count = [x for x in s if x == " "]
        if len(space_count) == 0: return s
        # Remove leading and trailing white spaces.
        s = s.lstrip()
        s = s.rstrip()  
        # Loop that will remove extra spaces inbetween characters.
        for i in range(len(s)): 
            if i < len(s) - 1 and s[i] == " " and s[i+1] == " ":
                # Keep removing whitespace.
                while s[i+1] == " ":
                    s = s[:i+1] + s[i+2:]     
    
        # Loop through 's' from the back and append words to r-
        # while keeping track of the position of the last space.
        j, r = len(s) - 1, ""
        last_space = None
        while j > 0:
            if s[j] == " ":
                if last_space == None:
                    r += s[j+1:]
                    r += " "
                else:
                    r += s[j+1:last_space]
                    r += " "
                last_space = j
            j -= 1
            
        r += s[j:last_space]    
        return r
