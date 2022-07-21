#
# @lc app=leetcode id=239 lang=python3
#
# [239] Sliding Window Maximum
#

# @lc code=start

from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        maxs = []
        window = deque()

        for index in range(k):
            while window and nums[index] > window[-1]:
                window.pop()
            window.append(nums[index])
        
        maxs.append(window[0])
        
        n = len(nums)
        for index in range(k, n):

            if nums[index-k] == window[0]:
                window.popleft()

            while window and nums[index] > window[-1]:
                window.pop()
            window.append(nums[index])

            maxs.append(window[0])

        return maxs


# @lc code=end

