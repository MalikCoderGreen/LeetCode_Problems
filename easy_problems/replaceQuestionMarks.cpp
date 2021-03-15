/*
1576. Replace All ?'s to Avoid Consecutive Repeating Characters

Given a string s containing only lower case English letters and the '?' character, 
convert all the '?' characters into lower case letters such that the final string does not contain any consecutive repeating characters. 
You cannot modify the non '?' characters.

It is guaranteed that there are no consecutive repeating characters in the given string except for '?'.

Return the final string after all the conversions (possibly zero) have been made. 
If there is more than one solution, return any of them. It can be shown that an answer is always possible with the given constraints.

Input: s = "?zs"
Output: "azs"
Explanation: There are 25 solutions for this problem. From "azs" to "yzs", all are valid. 
Only "z" is an invalid modification as the string will consist of consecutive repeating characters in "zzs".
*/

class Solution {
public:
    string modifyString(string s) {
        // Regardless of what s[0] is, "a" as a return is fine.
        if(s.length() == 1) return "a";
        
        // Get all letters and assign them to a vector using ascii values.
        vector<char> letters;
        for(int i = 97; i <= 122; i++) 
            letters.push_back(i);
        
        // Loop through s checking each character; special cases for char positions.
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            // First element case.
            if(s[i] == '?' && i == 0){
                while(s[i+1] == letters[count]) count++;
                s[i] = letters[count];
                count = 0;
            }
            
            // Case for all letters in between the first and the last.
            else if(s[i] == '?' && 0 < i < s.length()-1){
                while(s[i-1] == letters[count] || s[i+1] == letters[count])
                    count++;
                s[i] = letters[count];
                count = 0;
            }
            
            // Case for last element.
            else if(s[i] == '?' && i == s.length()-1){
                while(s[i-1] == letters[count]) count ++;
                s[i] = letters[count];
            }   
        }
          
        return s;
    }
};
