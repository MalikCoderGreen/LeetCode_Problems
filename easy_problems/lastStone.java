/*
1046. Last Stone Weight

We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
*/
class Solution {
    public int lastStoneWeight(int[] stones) {  
        // Create max-heap using priority queue.
        PriorityQueue<Integer> pQueue = new PriorityQueue<Integer>(Collections.reverseOrder());
        for(int i = 0; i < stones.length; i++)
            pQueue.add(stones[i]);
        
        // Continue to dequeue two elements each time from heap until we reach one element.
        while(pQueue.size() > 1){
            int y = pQueue.poll();
            int x = pQueue.poll();
            
            // Conditions from problem; only add y-x to heap if y > x.
            if(x == y) continue;        
            else if(x != y){
                y = y-x;
                pQueue.add(y);
            }         
        }   
        
        if(pQueue.peek() == null) return 0;  
        return pQueue.peek();   
    }
}
