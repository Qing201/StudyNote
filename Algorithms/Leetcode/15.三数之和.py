#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 三数之和
#

# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        left, mid, right = 0, 1, len(nums)-1
        solution = []

        while mid > left and mid < right:
            sum = nums[left] + nums[mid] + nums[right]
            if sum == 0:
                solution += [[nums[left], nums[mid], nums[right]]]
            elif sum > 0:
                

# @lc code=end

