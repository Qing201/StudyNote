#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 三数之和
#

# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        solution = []
        
        for i in range(0, len(nums) - 2): 
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i-1]:
                continue
            left, right = i+1, len(nums)-1


            while left < right:                
                sum = nums[i] + nums[left] + nums[right]
                if sum < 0:
                    left += 1
                if sum > 0:
                    right -= 1    
                elif sum == 0:
                    solution.append([nums[i], nums[left], nums[right]])
                    right -= 1
                    while left < right and nums[right] == nums[right+1]:
                        right -= 1
                    left += 1
                    while left < right and nums[left] == nums[left-1]:
                        left += 1
        
        return solution

# @lc code=end

