#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".  
Input: strs = ["flower","flow","flight"]
Output: "fl"
Input: strs = ["dog","racecar","car"]
Output: ""
*/

// Subroutine for longest prefix.
std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // Base case: string is empty. 
        if(strs.size() == 0)
            return "";
    
        // Just return the string itself if it is size of 1.
        if(strs.size() == 1)
            return strs[0];
        
        // Otherwise, we know that the list of strings is atleast size 2.
        // So we can set prefix to be equal to the first string.
        std::string prefix = strs[0];
        
        // Loop through every other word after the first and check for prefix similarity.
        for(int i = 1; i < strs.size(); i++){
            
            int k = 0;
            // New prefix that will hold the value of the new prefix if there is one. 
            std::string new_prefix = "";
            for(char c: strs[i]){
                if(prefix[k] == c){
                    new_prefix += c;
                }
                
                // We want to break immediately; for "flo" and "fli", when we see o == i,
                // then we immediately give prefix "fl" and break.
                else{
                    prefix = new_prefix;
                    break;
                }
                
                k++;  
            }     
            prefix = new_prefix;
            }
        
        return prefix;
}  


int main(){

// Here is where test outputs can be changed to see different results.
std::vector<std::string> strs;
strs.insert(strs.begin(), "flower");
strs.insert(strs.begin(), "flow");
strs.insert(strs.begin(), "flight");

std::string res = longestCommonPrefix(strs);
std::cout << "Longest common prefix: " << res << std::endl;




return 0;
}
