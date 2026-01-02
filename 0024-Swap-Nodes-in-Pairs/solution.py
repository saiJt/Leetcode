# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0,head)
        prev = dummy

        while(prev.next is not None and prev.next.next is not None):
            a = prev.next
            b = a.next
            upc = b.next

            prev.next = b
            b.next = a
            a.next= upc
            prev = a

        
        return dummy.next
