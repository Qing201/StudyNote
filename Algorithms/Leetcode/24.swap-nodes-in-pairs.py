#
# @lc app=leetcode id=24 lang=python3
#
# [24] Swap Nodes in Pairs
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummyHead = ListNode(0, head)

        node = dummyHead

        while node.next and node.next.next:
            temp = node.next
            node.next = node.next.next
            temp.next = node.next.next
            node.next.next = temp
            node = temp
        
        return dummyHead.next
        

# @lc code=end

