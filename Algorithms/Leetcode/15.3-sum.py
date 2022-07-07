#
# @lc app=leetcode id=15 lang=python3
#
# [15] 3Sum
#

# @lc code=start



class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        ''' Answer 1'''
        ''' Index method'''
        sortNums = sorted(nums)
        n = len(sortNums)
        result = []
            
        for i in range(n-2):
            if i > 0 and sortNums[i-1] == sortNums[i]:
                continue
            
            if sortNums[i] > 0:
                break

            left, right = i+1, n-1

            while left < right:
                
                sum = sortNums[i] + sortNums[right] + sortNums[left] 
                
                if sum > 0:
                    while left<right and sortNums[right] == sortNums[right-1]:
                        right -= 1
                    right -= 1
                elif sum < 0:      
                    while left<right and sortNums[left] == sortNums[left+1]:
                        left += 1
                    left += 1
                else:
                    result.append([sortNums[i], sortNums[right], sortNums[left]])
                    while left<right and sortNums[left] == sortNums[left+1]:
                        left += 1
                    while left<right and sortNums[right] == sortNums[right-1]:
                        right -= 1
                    right -= 1
                    left += 1

        return result


        ''' Hashing answer '''
        ''' Run time error '''
        # two_sum = {}
        # result = []

        # for i in range(len(nums)):
        #     if -nums[i] in two_sum:
        #         for indexes in two_sum[-nums[i]]:
        #             if indexes[1] != i:
        #                 if sorted([nums[i], nums[indexes[0]], nums[indexes[1]]]) not in result:
        #                     # result.append(sorted([i, indexes[0], indexes[1]]))
        #                     result.append(sorted([nums[i], nums[indexes[0]], nums[indexes[1]]]))
        #     for j in range(i+1, len(nums)):

                
        #         sum = nums[i] + nums[j]
        #         if sum in two_sum:
        #             two_sum[sum].append([i,j])
        #         else:
        #             two_sum[sum] = [[i,j]]

        # return result

                    
# @lc code=end

