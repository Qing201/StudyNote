#
# @lc app=leetcode id=977 lang=python3
#
# [977] Squares of a Sorted Array
#

# @lc code=start
from typing import List


class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        
        # Method 1
        # n = len(nums)

        # negativeNumber = 0
        
        # for i in range(n):
        #     if nums[i] < 0:
        #         negativeNumber += 1
        #     nums[i] = nums[i] ** 2

        # left, right = negativeNumber - 1, negativeNumber

        # sortedList = []
        # while left >= 0 and right <= n-1:
        #     if nums[left] > nums[right]:
        #         sortedList.append(nums[right])
        #         right += 1
        #     else:
        #         sortedList.append(nums[left])
        #         left -= 1

        # # add remain numbers in list
        # while left >= 0:
        #     sortedList.append(nums[left])
        #     left -= 1

        # while right <= n-1:
        #     sortedList.append(nums[right])
        #     right += 1

        # return sortedList


        # Method 2
        n = len(nums)
        left, right = 0, n-1

        sortList = [0] * n

        for index in range(n-1, -1, -1):
            if abs(nums[left]) < abs(nums[right]):
                sortList[index] = nums[right] ** 2
                right -= 1
            else:
                sortList[index] = nums[left] ** 2
                left += 1

        return sortList


# @lc code=end

