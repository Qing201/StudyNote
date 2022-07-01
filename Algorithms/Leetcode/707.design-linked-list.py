#
# @lc app=leetcode id=707 lang=python3
#
# [707] Design Linked List
#

# @lc code=start

from itertools import count
from signal import raise_signal

from urllib3 import Retry


class Node:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class MyLinkedList:

    def __init__(self):
        self._head = Node(0)
        self._count = 0

    def get(self, index: int) -> int:
        if 0 <= index < self._count:
            temp = self._head
            for _ in range(index+1):
                temp = temp.next
            return temp.val
        else:
            return -1

    def addAtHead(self, val: int) -> None:
        self.addAtIndex(0, val)
        

    def addAtTail(self, val: int) -> None:
        self.addAtIndex(self._count, val)

    def addAtIndex(self, index: int, val: int) -> None:
        if 0 <= index <= self._count:
            temp = self._head
            for _ in range(index):
                temp = temp.next
            temp.next = Node(val, temp.next)
            self._count += 1
        else:
            return

    def deleteAtIndex(self, index: int) -> None:

        if 0 <= index < self._count:
            temp = self._head
            for _ in range(index):
                temp = temp.next
            temp.next = temp.next.next
            self._count -= 1
        else:
            return



# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
# @lc code=end

