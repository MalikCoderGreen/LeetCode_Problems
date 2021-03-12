/*
876. Middle of the Linked List

Given a non-empty, singly linked list with head node head, return a middle node of linked list.
If there are two middle nodes, return the second middle node.

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
*/
class Solution {
    public ListNode middleNode(ListNode head) {
        if(head.next == null) return head;
        
        // Get size of list.
        ListNode ptr = head;
        int size = 0;
        while(ptr != null){
            size++;
            ptr = ptr.next;
        }
        // Ceiling will ensure that if size is odd, the mid is returned.
        size = (int)Math.ceil(size / 2);
        ptr = head;
        for(int i = 0; i < size; i++)
            ptr = ptr.next;
        
        return ptr;
    }
}
