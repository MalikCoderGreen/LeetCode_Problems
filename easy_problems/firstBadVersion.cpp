/*
278. First Bad Version

You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. 
Implement a function to find the first bad version. You should minimize the number of calls to the API.

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // Assume from the jump that the first bad version is the first version.
        int firstBad = 1;
        // Begin checking versions from the latest down to the first.
        // Once we find the version that is the first instance of a good version,
        // we return 1 + the number of that good version.
        for(int i = n; i >= 1; i--)
            if(!isBadVersion(i))
                return i+1; 
                    
        
        return firstBad;
    }
};
