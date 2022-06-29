#
# @lc app=leetcode id=35 lang=python3
#
# [35] Search Insert Position
#



# @lc code=start
from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        # a = 0
        # b = len(nums) - 1
        # while a < b:
        #     i = (a + b) // 2
        #     if nums[i] > target:
        #         b = i
        #     elif nums[i+1] < target:
        #         a = i + 1
        #     else:
        #         break
        # i = (a + b) // 2
        # if nums[i] >= target:
        #     return i
        # else:
        #     return i + 1


        # Solution
        left, right = 0, len(nums) - 1

        while left <= right:
            middle = (left + right) // 2

            if nums[middle] < target:
                left = middle + 1
            elif nums[middle] > target:
                right = middle - 1
            else:
                return middle
        return right + 1

# @lc code=end

