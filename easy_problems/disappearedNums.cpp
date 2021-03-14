/*
448. Find All Numbers Disappeared in an Array

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Vector to hold missing numbers.
        std::vector<int> missing;  
        // Create a set to hold the values of nums (won't contain duplicates).
        std::set<int> uniqNums;
        for(int i: nums) uniqNums.insert(i);
        
        // Append missing numbers if not in set.
        for(int i = 1; i <= nums.size(); i++){
            if(uniqNums.find(i) == uniqNums.end())
                missing.push_back(i);          
        }
        
        return missing;     
    }
};
