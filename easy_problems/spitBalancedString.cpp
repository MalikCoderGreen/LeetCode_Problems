/*
1221. Split a String in Balanced Strings

Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it in the maximum amount of balanced strings.
Return the maximum amount of split balanced strings.

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

Input: s = "RLLLLRRRLR"
Output: 3
Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.
*/

class Solution {
public:
    int balancedStringSplit(string s) {
        
        // Maintain the balance of 'L' and 'R'.
        // If balance is ever equal to 0, then we-
        // Know we have an even number of 'L's and 'R's.
        int balance = 0;
        int numStrings = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'L') balance++;
            else balance--;
            
            if(balance == 0) numStrings++;     
        }
        
        return numStrings;
    }
};
