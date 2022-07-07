#
# @lc app=leetcode id=350 lang=python3
#
# [350] Intersection of Two Arrays II
#

# @lc code=start
from calendar import c
from collections import defaultdict


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        ''' Answer 1 '''
        # nums1Dict = defaultdict(int)
        # nums2Dict = defaultdict(int)
        # commonNums = []

        # for char in nums1:
        #     if nums1Dict.get(char):
        #         nums1Dict[char] += 1
        #     else:
        #         nums1Dict[char] = 1
        
        # for char in nums2:
        #     if nums2Dict.get(char):
        #         nums2Dict[char] += 1
        #     else:
        #         nums2Dict[char] = 1
        

        # for char in nums1Dict:
        #     if nums2Dict.get(char):
        #         for _ in range(min(nums1Dict[char], nums2Dict[char])):
        #             commonNums.append(char)

        # return commonNums
                
        ''' Answer 2 '''
        numsDict = {}
        commonNums = []

        for num in nums1:
            numsDict[num] = numsDict.get(num, 0) + 1
        
        for num in nums2:
            if num in numsDict and numsDict[num] > 0:
                commonNums.append(num)
                numsDict[num] -= 1
        
        return commonNums

        
# @lc code=end

