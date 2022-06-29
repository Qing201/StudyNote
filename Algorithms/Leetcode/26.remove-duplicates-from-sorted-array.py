#
# @lc app=leetcode id=26 lang=python3
#
# [26] Remove Duplicates from Sorted Array
#

# @lc code=start

from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        fastIndex, slowIndex = 1, 0 
        n = len(nums)
        while fastIndex <= n-1:
            if nums[fastIndex] == nums[slowIndex]:
                fastIndex += 1
            else:
                slowIndex += 1
                nums[slowIndex] = nums[fastIndex]
                fastIndex += 1
        return slowIndex + 1

# @lc code=end

