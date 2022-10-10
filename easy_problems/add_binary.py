"""
67. Add Binary
Given two binary strings a and b, return their sum as a binary string.

Input: a = "11", b = "1"
Output: "100"

Input: a = "1010", b = "1011"
Output: "10101"
"""

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        c = "" # Return answer
        carry = False # Switch to keep track of the '1's that need to be carried to the next bit
        a, b = list(a), list(b)
        extra_bits = [] # Will be assigned to the longest string of bits between 'a' and 'b'
        if len(a) > len(b):
            extra_bits = a
        elif len(b) > len(a):
            extra_bits = b

        # Add all bits until one of the two strings go empty or both go empty together
        while len(a) > 0 and len(b) > 0:
            a_bit, b_bit = a.pop(-1), b.pop(-1)
            if a_bit == "1" and b_bit == "1":
                if carry == True:
                    c += "1"
                    carry = True
                else:
                    c += "0"
                    carry = True

            elif a_bit == "0" and b_bit == "0":
                if carry == True:
                    c += "1"
                    carry = False

                else:
                    c += "0"
            else:
                if carry:
                    c += "0"
                else:    
                    carry = False
                    c += "1"
        
        # If we ended with a carry from the above addition, need to continue
        if carry == True:
            while len(extra_bits) > 0:
                bit = extra_bits.pop(-1)
                if carry and bit == "1":
                    c += "0"
                    carry = True
                else:
                    if carry and bit == "0":
                        c += "1"
                        carry = False
                    elif len(extra_bits) == 0 and bit == "1":
                        c += "1"
                        carry = False
                    elif not carry:
                        c += bit
            if carry:
                c += "1"

        # Easy case where we just add the remaining bits from the longer string between a and b
        else:
            if extra_bits:
                return "".join(extra_bits) + c[::-1]

        return c[::-1] # Reverse for correct answer
