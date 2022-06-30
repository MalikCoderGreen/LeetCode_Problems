class Solution {
    public int sumSubArr(int[] sub){
        int sum = 0;
        for(int i = 0; i < sub.length; i++)
            sum += sub[i];
        
        return sum;
    }
    public int pivotIndex(int[] nums) {
         // ** USED HINT **
        /*
        We can precompute prefix sums P[i] = nums[0] + nums[1] + ... + nums[i-1]. 
        Then for each index, the left sum is P[i], 
        and the right sum is P[P.length - 1] - P[i] - nums[i].
        */
        int[] P = new int[nums.length];
        int count = 0;
        for(int i = 1; i < nums.length; i++){
            int leftSum = sumSubArr(Arrays.copyOfRange(nums, 0, count+1));
            count++;
            P[i] = leftSum;  
        }
        
        for(int i = 0; i < nums.length; i++){
            int leftSum = P[i];
            int rightSum = ((P[P.length - 1] - P[i] - nums[i]) + nums[nums.length - 1]);
            if(leftSum == rightSum)
                return i;
        }
                
        return -1;
    }    
}
