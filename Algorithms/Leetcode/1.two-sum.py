#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start

class Solution:


    def twoSum(self, nums: list[int], target: int) -> list[int]:

        ''' Answer 1 '''
        rec = {}
        for i in range(len(nums)):
            rest = target - nums[i]
            if rest in rec:
                return [rec[rest], i]
            else:
                rec[nums[i]] = i
        return None

        ''' Stupid Answer '''
        # index1 = 0
        # index2 = 1
        # while True:
        #     try:
        #         index2 = nums[index1+1:len(nums)].index(target - nums[index1]) + index1 + 1
        #         break
        #     except:
        #         index1 += 1

        # return list([index1, index2])


# @lc code=end

