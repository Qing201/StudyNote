#
# @lc app=leetcode.cn id=283 lang=python3
#
# [283] 移动零
#

# @lc code=start
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        fast, slow = 0, 0
        n = len(nums)
        while (fast <= n-1):
            if nums[fast] != 0:
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        while (slow <= n-1):
            nums[slow] = 0
            slow += 1
            
# @lc code=end

