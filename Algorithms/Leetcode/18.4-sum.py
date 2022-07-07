#
# @lc app=leetcode id=18 lang=python3
#
# [18] 4Sum
#

# @lc code=start
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        nums.sort()
        res = []
        n = len(nums)

        for a in range(n-3):
            if a != 0 and nums[a-1] == nums[a]:
                continue
            
            for b in range(a+1, n-2):
                if b != a+1 and nums[b-1] == nums[b]:
                    continue

                c, d = b+1, n-1

                while c < d:
                    sum = nums[a] + nums[b] + nums[c] + nums[d]
                    if sum < target:
                        while c < d and nums[c+1] == nums[c]: 
                            c += 1
                        c += 1
                    elif sum > target:
                        while c < d and nums[d-1] == nums[d]: 
                            d -= 1
                        d -= 1
                    else:
                        res.append([nums[a], nums[b], nums[c], nums[d]])
                        while c < d and nums[c+1] == nums[c]: 
                            c += 1
                        c += 1
                        while c < d and nums[d-1] == nums[d]: 
                            d -= 1
                        d -= 1
        
        return res
          
        
# @lc code=end

