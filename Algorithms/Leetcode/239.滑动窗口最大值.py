#
# @lc app=leetcode.cn id=239 lang=python3
#
# [239] 滑动窗口最大值
#

# @lc code=start

from collections import deque

class myQueue:
    def __init__(self):
        self.queue = deque()
    
    def pop(self, num):
        if self.queue() and self.queue[0] == num:    
            self.queue.popleft()

    def add(self, num):
        if num > self.queue[0]:
            while self.queue:
                self.queue.popleft()
        else:
            while self.queue and self.queue[-1] < num:
                self.queue.pop()
        self.queue.append(num)

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        
# @lc code=end

