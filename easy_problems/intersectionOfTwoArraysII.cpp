/*
350. Intersection of Two Arrays II

Given two integer arrays nums1 and nums2, 
return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Create two maps that will hold the frequency of all numbers
        // in both 'nums1' and 'nums2'.
        std::map<int, int> m1, m2;
        // Intersection list for return.
        vector<int> intersection;
        
        // Lines 11-21 will add values from both lists into 'm1' and 'm2'.
        for(int i: nums1){
            if(m1.find(i) == m1.end())
                m1.insert({i, 1});
            else m1[i] += 1;
        }
        
        for(int i: nums2){
            if(m2.find(i) == m2.end())
                m2.insert({i, 1});
            else m2[i] += 1;
        }
        
        // Loop through 'm1' and check which keys are in 'm2'.
        // If we find that we have similar keys, we need to take
        // the minimum value between the two keys.
        for(auto it = m1.begin(); it != m1.end(); it++){
            // Key from m1 exists in m2.
            if(m2.count(it->first) > 0){
                int count = std::min(m2[it->first], m1[it->first]);
                for(int i = 0; i < count; i++)
                    intersection.push_back(it->first);
            }
        }
        
        return intersection;     
    }
};
