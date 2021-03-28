"""
1556. Thousand Separator

Given an integer n, add a dot (".") as the thousands separator and return it in string format.

Input: n = 987
Output: "987"

Input: n = 1234
Output: "1.234"

Input: n = 123456789
Output: "123.456.789"

Input: n = 0
Output: "0"

"""
class Solution:
    def thousandSeparator(self, n: int) -> str:
        # Convert n to a string.
        s = str(n)
        
        # Scan from back of string and work towards the beginning.
        # For every three digits, we want to insert a "." to the left-
        # of them.
        j = len(s)
        while j-3 > 0:
            j -= 3
            s = s[:j] + "." + s[j:]
            
        return s
