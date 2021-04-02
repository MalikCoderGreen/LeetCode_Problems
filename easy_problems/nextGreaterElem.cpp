/*

496. Next Greater Element I

You are given two integer arrays nums1 and nums2 both of unique elements, where nums1 is a subset of nums2.

Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, return -1 for this number.

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation:
For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
For number 1 in the first array, the next greater number for it in the second array is 3.
For number 2 in the first array, there is no next greater number for it in the second array, so output -1.

*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) { 
        vector<int>greaterElems;
        for(int i = 0; i < nums1.size(); i++){
            int nextGreater = -1;
            int j = 0;
            while(nums2[j] != nums1[i]) j++;
            for(j += 1; j < nums2.size(); j++){
                if(nums2[j] > nums1[i]){
                    nextGreater = nums2[j];
                    break;
                }    
            }
            greaterElems.push_back(nextGreater);
        }
    
        return greaterElems;  
    }
};
