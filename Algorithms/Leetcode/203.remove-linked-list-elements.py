#
# @lc app=leetcode id=203 lang=python3
#
# [203] Remove Linked List Elements
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        
        # Answer 1
        # temp = head
        # if temp == None:
        #     return head
        # while temp.val == val:
        #     if temp.next != None:
        #         temp.val = temp.next.val
        #         temp.next= temp.next.next
        #     else:
        #         return None
                
        # while temp.next != None:
        #     if temp.next.val == val:
        #         temp.next = temp.next.next
        #     else:
        #         temp = temp.next

        # return head

        # Answer 2:
        dummyHead = ListNode(0,head)

        temp = dummyHead

        while temp.next != None:
            if temp.next.val == val:
                temp.next = temp.next.next
            else:
                temp = temp.next

        return dummyHead.next
# @lc code=end

