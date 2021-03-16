/*
345. Reverse Vowels of a String

Write a function that takes a string as input and reverse only the vowels of a string.
Input: "hello"
Output: "holle"

Input: "leetcode"
Output: "leotcede"
*/

class Solution {
public:
    string reverseVowels(string s) {
        // Create a set to hold all vowels.
        std::set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        // Use two-pointer approach to start from beginning of s and the end of s.
        // We are done once i and j are equal.
        int i = 0, j = s.length()-1;
        while(i <= j){
            // Both i and j are vowels; swap.
            if(vowels.find(tolower(s[i])) != vowels.end() && vowels.find(tolower(s[j])) != vowels.end())
                std::swap(s[i++], s[j--]);
               
            // I is a vowel, but j is not.
            else if(vowels.find(tolower(s[i])) != vowels.end() && vowels.find(tolower(s[j])) == vowels.end())
                j--;
             
            // J is a vowel, but i is not.
            else if(vowels.find(tolower(s[i])) == vowels.end() && vowels.find(tolower(s[j])) != vowels.end())     
                i++;
              
            // Both i and j are not vowels.
            else{
                i++; 
                j--;
            }
        }
        
        return s;
    }
};
