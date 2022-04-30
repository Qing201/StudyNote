#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        num1, num2 = 0, 0

        i = 0
        while l1 != None:
            num1 += l1.val * 10**i
            l1 = l1.next
            i += 1
        
        j = 0
        while l2 :
            num2 += l2.val * 10**j
            l2 = l2.next
            j += 1
        
        num = num1+num2

        # l3 = []

        # k = 0
        # while num !=0 :
        #     temp= num % 10**(k+1)
        #     l3.append(temp)
        #     num -= temp * 10**k
        
        if num == 0:
            l3 = ListNode()
        
        else:
            l3 = ListNode(None)

            k = max(i, j)
            if num % 10**(k) != 0:
                l3.val = 1
                l3.next = None 
            while k !=0 :
                l3.next = l3
                temp = num // 10**(k-1)
                l3.val =
                temp % 10
                # num -= temp * 10**k
                k -= 1

        return l3
# @lc code=end

