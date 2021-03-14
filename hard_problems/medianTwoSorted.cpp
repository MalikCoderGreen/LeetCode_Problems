/*
4. Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Build elements from both lists into min_heap. 
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        // Merge both vectors together and add elements to min_heap.
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        for(int i = 0; i < nums1.size(); i++)
            min_heap.push(nums1[i]);
        
        // Dequeue from min_heap giving vector 'merged' elements in order.
        vector<int> merged;
        while(!min_heap.empty()){
            merged.push_back(min_heap.top());
            min_heap.pop();
        }
        
        // Figure out where the mid point is.
        // Two cases: 
        // Length of merged is odd so just return mid. 
        // Length of merged is even so return (mid-1 + mid) / 2.
        int mid = (merged.size() / 2);
        
        if(merged.size() % 2 != 0) return merged[mid];      
        return (double)(merged[mid-1] + merged[mid]) / 2;
    }
};
