/*
1200. Minimum Absolute Difference

Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.

Input: arr = [1,3,6,10,15]
Output: [[1,3]]
*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // Sort the array for more accurate checking.
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> pairs;
        // 'b' will be the next element ahead of the current.
        int b = 1;
        // Keep track of the minimum abs diff.
        int minAbsDiff = INT_MAX;
        // Loop through and check two consecutive values at a time.
        for(int i = 0; i < arr.size()-1; i++){
            // If we find there is a new smaller difference, 
            // we need to erase pairs if there are already-
            // values inside.
            if( i != b && abs(arr[i] - arr[b]) < minAbsDiff){
                if(pairs.size() > 0)
                    pairs.clear();
                
                minAbsDiff = abs(arr[i] - arr[b]);      
                pairs.push_back({arr[i],arr[b]});   
            }
            
            // Simply add a and b (arr[i], arr[b]) to pairs since-
            // they are equal to the current minimum abs diff.
            else if( i != b && abs(arr[i] - arr[b]) == minAbsDiff){
                minAbsDiff = abs(arr[i] - arr[b]);      
                pairs.push_back({arr[i],arr[b]});
            }
            
            b++;
        }
        
        return pairs;
        
    }
};
