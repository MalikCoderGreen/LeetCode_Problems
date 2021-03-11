/*
338. Counting Bits
Given an integer num, return an array of the number of 1's in the binary representation of every number in the range [0, num].

Input: num = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
*/

class Solution {
    public int[] countBits(int num) {
        // Trivial solution: convert binary to string and count for 1s.
        int[] ones = new int[num+1];  
        for(int i = 0; i < ones.length; i++){
            
            String s = Integer.toBinaryString(i);
            int count = 0;
            
            for(int j = 0; j < s.length(); j++)
                if(s.charAt(j) == '1') count++;
            
            ones[i] = count;
            count = 0;
        }
        
        return ones;
    }
}
