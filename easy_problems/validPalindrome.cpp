/*
125. Valid Palindrome

Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 1)
            return true;
        
        // Use string to hold all alpha and digit characters.
        string pureChars = "";
        for(char c: s)
            if(isalpha(c) || isdigit(c)) pureChars += tolower(c);
        
        // This means there were no alpha or digit characters in the original string 's'. 
        if(!pureChars.length())
            return true;
        
        // Loop with two pointer approach to find a possible mismatch for the string.
        int i = 0, j = pureChars.length() - 1;
        while(i < j){
            if(pureChars[i++] != pureChars[j--])
                return false;
        }
            
        return true;
        
    }
};
