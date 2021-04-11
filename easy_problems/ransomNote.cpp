
/*
383. Ransom Note

Given an arbitrary ransom note string and another string containing letters from all the magazines, 
write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Input: ransomNote = "a", magazine = "b"
Output: false

Input: ransomNote = "aa", magazine = "ab"
Output: false
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Create a map that keeps track of all chars in
        // magazine.
        map<char, int> usage;
        for(char c: magazine){
            if(usage.find(c) == usage.end()) usage.insert({c, 1});       
            else usage[c] += 1;
        }
        
        int count = 0, valid = 0;
        // Use a loop and check every char in 'ransomNote' and whether or not we can use a
        // char from 'magazine' in the string. If we can, decrease the value from the map by one.
        while(count < ransomNote.length()){
            // We can use a letter from the magazine map in the ransomNote.
            if(usage.find(ransomNote[count]) != usage.end() && usage[ransomNote[count]] > 0){
                usage[ransomNote[count]]--;
                valid++;
            }        
            count++;           
        }
            
        return valid == ransomNote.length();
    }
};
