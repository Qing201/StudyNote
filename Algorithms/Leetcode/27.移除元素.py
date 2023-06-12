#
# @lc app=leetcode.cn id=27 lang=python3
#
# [27] 移除元素
#

# @lc code=start
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:

        slow,fast = 0,0
        n = len(nums) - 1
        while fast <= n:
            if nums[fast] == val:
                fast += 1
            else:
                nums[slow] = nums[fast]
                slow += 1
                fast += 1
        return slow





        # left,right = 0,len(nums)-1
        # while left <= right:
        #     if nums[left] == val:
        #         while nums[right] == val:
        #             if right == left:
        #                 return left
        #             right = right - 1
        #         nums[left] = nums[right]
        #         right = right - 1
        #     left = left + 1
        # return left
    
# @lc code=end

