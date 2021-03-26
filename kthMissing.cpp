/*

1539. Kth Missing Positive Number

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Find the kth positive integer that is missing from this array.

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Create a set to hold all values from arr. 
        std::set<int> integers;
        for(int i: arr) integers.insert(i);
        
        // Loop through and increment count when we find a num-
        // not in 'integers' set.
        int count = 0;
        for(int i = 1; i < arr[arr.size()-1]; i++){
            if(integers.find(i) != integers.end())
                continue;  
            else
                count++;
            
            // If the kth missing is smaller than the largest-
            // then we cam return it before the loop ends.
            if(count == k)
                return i;
        }
        
        // If we get here, the missing kth number-
        // is larger than the last element. We need-
        // to add k and subtract other missed elements-
        // to find kth missing.
        return arr[arr.size()-1] + k - count;
    }
};
