# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        
        node_dict = {}
        count = 0
        curr = head
        
        while curr is not None:
            node_dict[count] = curr
            curr = curr.next
            count += 1
        
        N = count
        curr = head
        count = 0
        
        
        while count < floor(N/2):
            curr = node_dict[count]
            curr.next = node_dict[N-1 - count]
            node_dict[N-1 - count].next = node_dict.get(count+1)
            count+=1
        
        node_dict[floor(N/2)].next = None
        