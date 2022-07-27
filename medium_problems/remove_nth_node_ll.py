# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head.next:
            return None
        
        # [1, 2, 3, 4, 5] n
        # Get size of list
        ptr = head
        sz = 0
    
        while ptr:
            sz += 1
            ptr = ptr.next      
            
        count = sz
        ptr = head
        while count > n + 1:
            ptr = ptr.next
            count -= 1
        
        # nth node is the first element
        if count == n:
            tmp = head
            head = head.next
            del tmp
        
        # There is a node after the nth node to be removed
        if ptr.next.next:
            tmp = ptr.next.next
            del ptr.next
            ptr.next = tmp
        
        # The nth node is the last node
        else:
            tmp = ptr.next
            ptr.next = None
            del tmp          
            
        
        return head
