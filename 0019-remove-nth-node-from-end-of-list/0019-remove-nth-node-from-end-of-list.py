# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        
        queue = [head]
        
        while len(queue) < n:
            queue.append(queue[-1].next)
        
        if queue[-1].next is None:
            try:
                return queue[1]
            except:
                return None
        
        queue.append(queue[-1].next)
        while queue[-1].next is not None:
            queue.pop(0)
            queue.append(queue[-1].next)
            
        try:
            queue[0].next = queue[2]
        except:
            queue[0].next = None
            
        return head
        