#
# @lc app=leetcode id=704 lang=python3
#
# [704] Binary Search
#

# @lc code=start
from operator import index
from textwrap import indent
from typing import List


class Solution:

    def search(self, nums: List, target: int) -> int:
        self.target = target
        self.nums = nums
        index = self.indexSearch(0, len(nums)-1)
        return index

    def indexSearch(self, a, b):
        if a > b:
            return -1

        num = self.nums[a+(b-a)//2]
        if num == self.target:
            index = a+(b-a)//2
        elif num > self.target:
            index = self.indexSearch(a, a+(b-a)//2-1)
        else:
            index = self.indexSearch(a+(b-a)//2+1, b)
        return index


    # Solution
    #
    # def search(self, nums: List[int], target: int) -> int:
    #     left, right = 0, len(nums) - 1
    #     while left <= right:
    #         pivot = left + (right - left) // 2
    #         if nums[pivot] == target:
    #             return pivot
    #         if target < nums[pivot]:
    #             right = pivot - 1
    #         else:
    #             left = pivot + 1
    #     return -1


    def search(self, nums: List, target: int) -> int:
        left = 0; right = len(nums)
        while(left<=right):
            mid = (right+left)/2
            num = target[mid]
            if num == target:
                return mid
            elif num > target:
                right = mid-1
            elif num < target:
                left = mid+1
        return -1

    
# @lc code=end