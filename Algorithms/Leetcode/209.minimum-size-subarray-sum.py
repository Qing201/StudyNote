#
# @lc app=leetcode id=209 lang=python3
#
# [209] Minimum Size Subarray Sum
#

# @lc code=start
from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        slow = 0

        sum = 0

        minLen = n+1

        for quick in range(n):
            sum += nums[quick]
            while sum >= target:
                minLen = min(minLen, (quick - slow + 1))
                sum -= nums[slow]
                slow += 1

        if minLen == n+1:
            return 0
        else:
            return minLen
                

# @lc code=end

