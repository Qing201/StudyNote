#
# @lc app=leetcode id=49 lang=python3
#
# [49] Group Anagrams
#

# @lc code=start
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        strs_list = {}
        for word in strs:
            tuple_index = tuple(sorted(word))
            if strs_list.get(tuple_index):
                strs_list[tuple_index].append(word)
            else:
                strs_list[tuple_index] = [word]
        return strs_list.values()
# @lc code=end

