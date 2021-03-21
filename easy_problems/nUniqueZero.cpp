/*
1304. Find N Unique Integers Sum up to Zero

Given an integer n, return any array containing n unique integers such that they add up to 0.

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].

Input: n = 3
Output: [-1,0,1]

Input: n = 1
Output: [0]
*/
class Solution {
public:
    vector<int> sumZero(int n) {   
        vector<int> zeroSum;
        if(n % 2 != 0) zeroSum.push_back(0);
        
        int k = 0;
        // Statement to add extra to vector if n is even.
        if(n % 2 == 0) k += 1;
        
        // This method of adding numbers will simply add-
        // a positive number and it's negative counterpart.
        int count = 1;
        // Loop through and alternate using modulus.
        for(int i = 1; i < n + k; i++){
            if(i % 2 != 0) zeroSum.push_back(count);
            else zeroSum.push_back(-count++);
        }
        
        return zeroSum;
    }
};
