
/*
Remove Linked List Elements (easy difficulty)
Remove all elements from a linked list of integers that have value val.

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/



class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Base case: no list. 
        if(!head)
            return nullptr;
        
        // Head for new list return.
        ListNode *head2 = nullptr;
        // Use queue to push elements that are not equal to 'val'.
        queue<int> newList;
        
        // Traverse through original list and append to queue any values not equal to 'val'.
        ListNode *cursor = head;  
        while(cursor){
            if(cursor->val != val){
                newList.push(cursor->val);
            }
            cursor = cursor->next;
        }
        // Case where the entire list has only 'val' as elements.
        if(newList.empty())
            return head2;
        
        // Assign head2 to the first value from the queue.
        ListNode *firstNode = new ListNode;
        firstNode->val = newList.front();
        newList.pop();
        head2 = firstNode;
        
        // Keep inserting elements until queue has no more values for insertion.
        ListNode *cursor2 = head2;  
        while(!newList.empty()){
            ListNode *node = new ListNode;
            node->val = newList.front();
            
            while(cursor2->next)
                cursor2 = cursor2->next;
            
            cursor2->next = node;
            cursor2 = cursor2->next; 
            newList.pop();
        }
        
        // Return new list with removed elements.
        return head2;
    }
};
