#
# @lc app=leetcode id=347 lang=python3
#
# [347] Top K Frequent Elements
#

# @lc code=start

import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        nums_count = {}
        for n in nums:
            nums_count[n] = nums_count.get(n, 0) + 1

        heap_list = []
        for item, count in nums_count.items():
            if len(heap_list) < k:
                heapq.heappush(heap_list, (count,item))
            else:
                heapq.heappushpop(heap_list, (count,item))
            
        k_nums = []
        for n in heap_list:
            k_nums.append(n[1])

        return k_nums

# @lc code=end

