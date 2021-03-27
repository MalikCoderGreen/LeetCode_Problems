"""
25. Reverse Nodes in k-Group

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]

"""
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        # Append all values from the linked list-
        # into an array.
        nodes = []
        ptr = head
        sz = 0
        while ptr: 
            sz += 1
            nodes.append(ptr.val)
            ptr = ptr.next  
        
        # Reverse the values of groups k at a time.
        # There is a check to see if the number of nodes left to be reversed-
        # are less than k: if we need to reverse k = 2 groups and there is 1 node-
        # left in the array, then we do not have enough nodes left to reverse so we-
        # break out of the loop.
        i, stop = 0, k
        nodes_left = sz
        while i != len(nodes):
            nodes[i:stop] = nodes[i:stop][::-1]
            i += k 
            stop += k
            nodes_left -= k
            if nodes_left < k: break
            
        # Overrite the values of the original list with the modified-
        # array.
        ptr = head
        count = 0
        while(ptr):
            ptr.val = nodes[count]
            count += 1
            ptr = ptr.next
        
        return head
            
