# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class RecursiveSolution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next: return head
        newHead = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return newHead

class IterativeSolution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node = head
        prev = None
        while node:
            nextNode = node.next
            node.next = prev
            prev = node
            node = nextNode
        return prev

