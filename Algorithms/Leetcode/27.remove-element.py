#
# @lc app=leetcode id=27 lang=python3
#
# [27] Remove Element
#

# @lc code=start
from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        lastIndex = len(nums) - 1
        i = 0
        while i  <= lastIndex:
            if nums[i] == val:
                for j in range(lastIndex, i, -1):
                    if nums[j] != val:
                        nums[i] = nums[j]
                        lastIndex = j-1
                        break
                else:
                    lastIndex = i - 1
     
            i += 1
            
        return lastIndex + 1
        
# @lc code=end

