/*

414. Third Maximum Number

Given integer array nums, return the third maximum number in this array. 
If the third maximum does not exist, return the maximum number.

Input: nums = [3,2,1]
Output: 1
Explanation: The third maximum is 1.

Input: nums = [1,2]
Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Use set to get all unique digits from nums in order.
        std::set<int> digits;
        for(int i : nums)
            digits.insert(i);
        
        
        // Use iterator to find third maximum.
        std::set<int>::iterator thirdMax = (digits.begin());
        // If the size isn't atleast 3, then we can just return the max element.
        if(digits.size() < 3) return *std::prev(digits.end());
        
        // Otherwise, move the iterator until we reached the third to last element.
        int count = 0;
        while(count < digits.size()-3){ 
            count++;
            thirdMax++;
        }
        
        return *(thirdMax);
            
        
    }
};
