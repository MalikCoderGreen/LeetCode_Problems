# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head

        odd, even = head, head.next
        evenHead = even
        while odd.next and even.next:
            odd.next = even.next
            even.next = even.next.next
            odd = odd.next
            even = even.next
            
        odd.next = evenHead
            
            
        return head