#
# @lc app=leetcode.cn id=704 lang=python3
#
# [704] 二分查找
#

# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:

        left = 0
        right = len(nums) - 1

        while left <= right :
            mid = (left + right)//2
            num = nums[mid]
            if num == target:
                return mid
            elif num < target:
                left = mid+1
            else:
                right = mid-1

        return -1

# @lc code=end

