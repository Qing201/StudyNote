#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        l = dict()
        for i, x in enumerate(nums):
            if x in l:
                return [i, l[x]]
            else:
                l[target-x] = i
        

# @lc code=end
