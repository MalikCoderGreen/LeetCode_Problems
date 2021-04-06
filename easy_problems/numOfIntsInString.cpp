/*
1805. Number of Different Integers in a String

You are given a string word that consists of digits and lowercase English letters.

You will replace every non-digit character with a space. For example, "a123bc34d8ef34" will become " 123  34 8  34". 
Notice that you are left with some integers that are separated by at least one space: "123", "34", "8", and "34".
Return the number of different integers after performing the replacement operations on word.

Two integers are considered different if their decimal representations without any leading zeros are different.

Input: word = "a123bc34d8ef34"
Output: 3
Explanation: The three different integers are "123", "34", and "8". Notice that "34" is only counted once.
*/

class Solution {
public:
    int numDifferentIntegers(string word) {
        // Set will hold all distinct integers in 'word'.
        set<string> uniqueInts;
        int i = 0;
        while(i < word.length()){
            if(isalpha(word[i]))
                word[i] = ' '; 
            i++;
        }

        i = 0;
        // Main loop to add integers in string to set.
        while(i < word.length()){
            // We have found and 'int' if we hit this conditional.
            if(!isspace(word[i])){
                int j = i;
                string strInt = "";  
                // This conditional handles 'ints' with leading zeros.
                if(j < word.length() && word[j] == '0'){
                    // First loop erases all zeroes up until a non-zero value.
                    // Second loop appends all other values to 'strInt'.
                    while(j < word.length() && word[j] == '0')
                        word[j++] = ' ';              
                    while(j < word.length() && !isspace(word[j]))
                        strInt += word[j++];
                           
                    uniqueInts.insert(strInt); 
                    i = j;
                }
                
                // If we enter here, we know this is an 'int' with no leading zeros-
                // so just append it to 'strInt'.
                else{
                    while(j < word.length() && !isspace(word[j]))
                        strInt += word[j++];   
                }
    
                i = j;
                uniqueInts.insert(strInt);
            }
            // Else, word[i] == ' '; keep moving.
            else i++;
        }
        // Sets only contain unique values, so return the size of 'uniqueInts'.
        return uniqueInts.size();
    }
};
