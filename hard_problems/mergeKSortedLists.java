
/*
23. Merge k Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Input: lists = []
Output: []
*/

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0) return null;
        
        // Create a min heap for nodes in all lists.
        PriorityQueue<Integer> nodes = new PriorityQueue<Integer>(); 
       
        // Traversal pointer.
        ListNode ptr; 
        // Assign all values in all lists to heap.
        for(ListNode list: lists){   
            ptr = list;
            while(ptr != null){
                nodes.add(ptr.val);
                ptr = ptr.next; 
            }
        }
        
        // If nothing is in heap, empty lists!
        if(nodes.isEmpty()) return null;
        
        // Assign elements in order from heap to new list.
        ListNode head = new ListNode(nodes.poll());
        ptr = head;
        while(!nodes.isEmpty()){
            ListNode k = new ListNode(nodes.poll());
            ptr.next = k;
            ptr = ptr.next;
        } 
        return head;      
    }
}
