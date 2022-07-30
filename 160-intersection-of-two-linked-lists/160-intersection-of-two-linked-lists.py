# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, A: ListNode, B: ListNode) -> Optional[ListNode]:
        first_list_map = {}
        temp = A
        while temp:
            first_list_map[temp] = 1
            temp = temp.next

        temp = B
        while temp:
            if temp in first_list_map:
                return temp
            temp = temp.next
        return None