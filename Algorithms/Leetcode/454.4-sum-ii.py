#
# @lc app=leetcode id=454 lang=python3
#
# [454] 4Sum II
#

# @lc code=start
class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        
        sumMap = {}

        res = 0

        for i in range(len(nums1)):
            for j in range(len(nums2)):
                sum = nums1[i] + nums2[j]
                sumMap[sum] = sumMap.get(sum, 0) + 1

        for k in range(len(nums3)):
            for l in range(len(nums4)):
                res += sumMap.get(-(nums3[k] + nums4[l]), 0)
        
        return res

# @lc code=end

