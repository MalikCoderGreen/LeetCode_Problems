/*
941. Valid Mountain Array

Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Input: arr = [2,1]
Output: false

Input: arr = [3,5,5]
Output: false

Input: arr = [0,3,2,1]
Output: true
*/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        // Two violations: array of size < 3; beginning value being bigger than next.
        if(arr.size() < 3 || arr[0] > arr[1])
            return false;
              
        // Switch to determine if a peak is found.
        bool peakFound = false;
        for(int i = 0; i < arr.size()-1; i++){
            // Check for duplicates back to back which violates.
            if(arr[i] == arr[i+1])
                return false;
            
            // Keep going to search for a peak.
            if(arr[i] < arr[i+1] && !peakFound)
                continue;
            
            // Found the peak.
            else if(arr[i] > arr[i+1] && !peakFound)
                peakFound = true;
            
            // All values after peak should be strictly decreasing.
            else if(arr[i] < arr[i+1] && peakFound)
                return false;
                
        }
        
        // If we have no peak, this is not a mountain array.
        if(!peakFound)
            return false;
        
        return true;
    }
};
