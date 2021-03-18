/*
896. Monotonic Array

An array is monotonic if it is either monotone increasing or monotone decreasing.
An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.

Input: [1,2,2,3]
Output: true

Input: [6,5,4,4]
Output: true

Input: [1,3,2]
Output: false
*/

class Solution {
    public:
    bool isMonotonic(vector<int>& A) {
        // Bool variables to determine what we expect-
        // the array to be based on first element compared-
        // to the last element.
        bool monoD = false, monoI = false, equal = false;

        if(A[0] > A[A.size()-1]) monoD = true;
        else if(A[0] < A[A.size()-1]) monoI = true;
        else equal = true;
        
        // Loop through array to determine if the array is mono inceasing / decreasing.
        // If we get to the end of the for loop, the array is monotonic.
        for(int i = 0; i < A.size()-1; i++){
            if(A[i] < A[i+1] && monoD) return false;
            else if(A[i] > A[i+1] && monoI) return false;
            else if((A[i] > A[i+1] || A[i] < A[i+1]) && equal) return false;
        }

        return true;
    }
};
