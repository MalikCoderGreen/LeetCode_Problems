/*
Given a linked list, swap every two adjacent nodes and return its head. (medium difficulty)
Input: head = [1,2,3,4]
Output: [2,1,4,3]
Input: head = []
Output: []
Input: head = [1]
Output: [1]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: list is empty. 
        if(!head)
            return NULL;
        
        // One element case. 
        if(head && head->next == nullptr)
            return head;
        
        // Both pointers that will swap adjacent nodes. Start right one ahead of left. 
        ListNode *rightCursor = head->next, *leftCursor = head;
        
        // Loop for swapping, when the right ptr is not pointing to something, end loop.
        while(rightCursor != nullptr){
            swap(leftCursor->val, rightCursor->val);
            
            // Statements to ensure that the pointers have not gone off of the list.
            // Want to always try and move pointers two steps at a time.
            leftCursor = leftCursor->next;
            if(!leftCursor)
                break;
            leftCursor = leftCursor->next;
            
            rightCursor = rightCursor->next;
            if(!rightCursor)
                break;
            rightCursor = rightCursor->next;
        }
        
        return head;  
        
    }
};
