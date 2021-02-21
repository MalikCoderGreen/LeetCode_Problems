/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Input: haystack = "hello", needle = "ll"
Output: 2

Input: haystack = "aaaaa", needle = "bba"
Output: -1

Input: haystack = "", needle = ""
Output: 0
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        // Base case: needle is an empty string. 
        if(!needle.length())
            return 0;
        
        // Case when haystack is one char and needle is one char. 
        if(needle.length() == 1 && haystack.length() == 1 && haystack[0] == needle[0])
            return 0;
        
        int match = 0;
        for(int i = 0; i < haystack.length(); i++){
            // If we find first possible char of needle.
            if(haystack[i] == needle[0]){
                int j = 0;
                // Loop through substring of haystack and check for potential match.
                while(j < needle.length()){
                    if(needle[j] == haystack[j+i]){
                        match += 1;
                        j++;
                    }
                    
                    else
                        break;
                           
                }
                
                // The substring within the string = needle. - 
                // so, just return i indicating the start index for that substring,
                if(match == needle.length())
                    return i;
                match = 0;
            }    
        }
        
        
        return -1;
        
    }
};
