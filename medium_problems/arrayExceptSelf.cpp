/*

238. Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
           
        vector<int> pArr; // Product list to hold result.
        int z = 0; // counter to the hold number of zeroes.
        int acc = 1; // Hold the product of all non-zero numbers.
        
        // Loop will accumulate into 'acc' all non-zero numbers and-
        // if we encounter a zero, don't add it to 'acc'; increase z instead.
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0) acc *= nums[i];
            else z++;  
        }
             
        // Loop will change values of pArr dependent on if they are non-zero or not.
        // Top condtionals will handle non-zero values and bottom conditionals handle-
        // zero values. Both are dependent on the count of 'z'.
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] != 0 && z >= 1) pArr.push_back(0);
            else if(nums[i] != 0 && z  == 0) pArr.push_back(acc / nums[i]);
            
       
            if(nums[i] == 0 && z > 1) pArr.push_back(0);
            else if(nums[i] == 0 && z == 1) pArr.push_back(acc);
        }
            
        return pArr;
    }
};
