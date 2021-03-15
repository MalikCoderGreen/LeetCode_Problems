/*
349. Intersection of Two Arrays

Given two arrays, write a function to compute their intersection.
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {     
        // Create two sets to hold values of both lists.
        std::set<int> same1, same2;
        for(int i: nums1) same1.insert(i);
        for(int i: nums2) same2.insert(i);
        
        // Loop through first set and check if any values are in the second set.
        // If so, append to intersect vector.
        std::vector<int> intersect;
        for(auto it = same1.begin(); it != same1.end(); it++){
            if(!(same2.find(*it) == same2.end()))
                intersect.push_back(*it);
        }
           
        return intersect;
    }
    
};
