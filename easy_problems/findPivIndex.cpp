/*
724. Find Pivot Index

Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of- 
the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. 
This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
*/
class Solution {
public:
    /* Function to compute the sum of a given subarray.
    *  Args: l, r (indexes to the beginning `l` and end `r` of subarray).
    *  Reutrn: sum of given subarray.
    */
    int subArrSum(vector<int>& sub, int l, int r){
        // Base case: no need to compute since-
        // sub array size = 0.
        if(l == r) return 0;
        
        int sum = 0;
        for(int i = l; i < r; i++)
            sum += sub[i];     
        return sum;
    }
    
    int pivotIndex(vector<int>& nums) {   
        // Loop through and immediately return index-
        // if we find that the subarray sums to it's-
        // left and right are equal.
        for(int i = 0; i < nums.size(); i++){
            int lSum = subArrSum(nums, 0, i);
            int rSum = subArrSum(nums, i+1, nums.size());
            
            // We have found a pivot.
            if(lSum == rSum)
                return i;
        }
        
        // We have found nothing if we have gotten this far.
        return -1;
    }
};
