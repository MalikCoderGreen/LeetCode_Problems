/*
83. Remove Duplicates from Sorted List

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.

Input: head = [1,1,2]
Output: [1,2]

Input: head = [1,1,2,3,3]
Output: [1,2,3]
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Cases for an empty list and a one element list.
        if(!head || !head->next) return head;
        
        // Use two pointers to traverse list; cursor is always head of prev.
        ListNode* prev = head;
        ListNode* cursor = head->next;
        
        while(cursor){
            // We have found duplicate; use prev to-
            // point to next unique val.
            if(prev->val == cursor->val){
                prev->next = cursor->next;
                delete cursor;
                cursor = prev->next;
            }
            
            // Both are distinct, continue traversal.
            else{
                prev = prev->next;
                cursor = cursor->next;
            }
            
        }
        
        return head;
        
        
    }
};
