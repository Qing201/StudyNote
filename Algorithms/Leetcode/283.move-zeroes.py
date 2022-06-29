#
# @lc app=leetcode id=283 lang=python3
#
# [283] Move Zeroes
#

# @lc code=start
from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        slowIndex, fastIndex = 0, 0

        n = len(nums)

        while fastIndex < n:
            if nums[fastIndex] == 0:
                fastIndex += 1
            else:
                if slowIndex != fastIndex:
                    nums[slowIndex] = nums[fastIndex]
                    nums[fastIndex] = 0
                fastIndex += 1
                slowIndex += 1
        
# @lc code=end

