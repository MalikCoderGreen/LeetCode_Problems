/*

830. Positions of Large Groups

In a string s of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".

A group is identified by an interval [start, end], 
where start and end denote the start and end indices (inclusive) of the group. In the above example, "xxxx" has the interval [3,6].

A group is considered large if it has 3 or more characters.
Return the intervals of every large group sorted in increasing order by start index.

Input: s = "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the only large group with start index 3 and end index 6.

*/
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> largestPos;
        int i = 0;
        // Start from first char in string, and loop-through 's' jumping-
        // by j at a time.
        while(i < s.length()){
            int j = i;
            // Keep incrementing j if we find char matching to s[i].
            while(s[j] == s[i]) j++; 
            // Substring must have size >= 3 to add start and end positions.
            if( j - i >= 3)
                largestPos.push_back({i, j-1});
            
            i = j;
        }
        
        return largestPos; 
    }
};
