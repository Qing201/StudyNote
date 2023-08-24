#
# @lc app=leetcode.cn id=26 lang=python3
#
# [26] 删除有序数组中的重复项
#

# @lc code=start
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        quick = 0
        slow = 0
        size = len(nums) - 1 
        record = []

        while quick <= size:
            if nums[quick] not in record:
                record.append(nums[quick])
                nums[slow] = nums[quick]
                slow += 1
            quick += 1
        return slow
    
# @lc code=end

