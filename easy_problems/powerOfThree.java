/*
326. Power of Three

Given an integer n, return true if it is a power of three. Otherwise, return false.
An integer n is a power of three, if there exists an integer x such that n == 3x.

Input: n = 27
Output: true

Input: n = 0
Output: false

Input: n = 9
Output: true

Input: n = 45
Output: false
*/
class Solution {
    public boolean isPowerOfThree(int n) {
        if(n==0) return false;
        if(n==1 || n==3) return true;
        
        // Keep dividing until 3 is reached.   
        while(n % 3 == 0 && n != 3){  
            n /= 3; 
            if(n == 3)
                return true;
        }
        
        return false;
    }
}
