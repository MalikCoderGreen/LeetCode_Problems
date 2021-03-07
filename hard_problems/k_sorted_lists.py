"""
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

Input: lists = [[]]
Output: []
"""
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if len(lists) == 0:
            return None
        
        aux = [] 
        # Append all nodes to aux list. 
        for i in range(len(lists)):
            ptr = lists[i]
            while ptr: 
                aux.append(ptr.val)
                ptr = ptr.next
       
        # Sort the list.
        aux.sort()
        
        if len(aux) == 0:
            return None
        
        # Loop for linked list insertion from aux list.
        head = ListNode(aux[0])
        ptr_2 = head
        for i in range(1,len(aux)):
            tmp = ListNode(aux[i])
            ptr_2.next = tmp
            ptr_2 = tmp
        
        return head
