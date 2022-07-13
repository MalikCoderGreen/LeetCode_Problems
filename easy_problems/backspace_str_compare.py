"""
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
"""
class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        s_stk, t_stk = [], []
        
        # Loop through and push non-backspace chars into stack.
        def helper_func(stk, seq):
            # pop off chars for every backspace char.
            i = 0
            while i < len(seq):
                if seq[i] != '#':
                    stk.append(seq[i])
                
                else:
                    # Case where the backspace is the first char.
                    if len(stk) != 0:
                        stk.pop(len(stk) - 1)
                
                i += 1    
        
        helper_func(s_stk, s)
        helper_func(t_stk, t)            
            
        
        return ''.join(s_stk) == ''.join(t_stk)
                
