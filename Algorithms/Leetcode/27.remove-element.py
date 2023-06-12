#
# @lc app=leetcode id=27 lang=python3
#
# [27] Remove Element
#

# @lc code=start
from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        left,right = 0,len(nums)-1
        while left < right:
            if nums[left] == val:
                while right == val:
                    right = right - 1
                    if right == left:
                        break
                nums[left] = nums[right]
            left = left + 1
        return right
        
# @lc code=end

