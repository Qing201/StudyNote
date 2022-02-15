#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
import numpy as np


class Solution:


    def twoSum(self, nums: list[int], target: int) -> list[int]:
        index1 = 0
        index2 = 1
        while True:
            try:
                index2 = nums[index1+1:len(nums)].index(target - nums[index1]) + index1 + 1
            except:
                index1 += 1
                continue
            break

        return list([index1, index2])
    '''
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        all_index = np.argsort(nums)
        sort_nums = np.sort(nums)
        n = len(sort_nums)

        index = 0
        index2 = self.Search(sort_nums, index+1, n-1, target-sort_nums[index])

        while sort_nums[index] + sort_nums[index2] != target:
            index2 = self.Search(sort_nums, index, index2, target-sort_nums[index])
            if sort_nums[index2] == target - sort_nums[index]:
                break
            else:
                index += 1
        return list([all_index[index],all_index[index2]])

    def Search(self, array, f, l, target):
        index = l
        if l != f:
            m = (f + l)//2
            if target == array[m]:
                index = m
            elif target < array[m]:
                index = self.Search(array, f, m, target)
            else:
                index = self.Search(array, m+1, l, target)

        return index
    '''


# @lc code=end

