/*
Is Subsequence

Given two strings s and t, check if s is a subsequence of t.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters-
without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Input: s = "abc", t = "ahbgdc"
Output: true

Input: s = "axc", t = "ahbgdc"
Output: false
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Counter to keep track of number of matched chars.  
        int count = 0;
        
        // Loop through t and check for possible sequence.
        for(int i = 0; i < t.length(); i++){
            if(t[i] == s[count]){  
                count++;
            }   
        }
        // Count must equal the orginial subsequence length inorder to be valid.
        if(count != s.length())
            return false;
        
        return true;  
    }
};

