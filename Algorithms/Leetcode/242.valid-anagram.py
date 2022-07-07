#
# @lc app=leetcode id=242 lang=python3
#
# [242] Valid Anagram
#

# @lc code=start


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        # Answer 1
        # recordList = [0] * 26

        # for x in s:
        #     recordList[ord(x)- ord("a")] += 1
        # for y in t:
        #     recordList[ord(y)- ord("a")] -= 1

        # for i in recordList:
        #     if i != 0:
        #         return False

        # return True

        # Answer 2

        from collections import defaultdict

        s_dict = defaultdict(int)
        t_dict = defaultdict(int)
        
        for x in s:
            s_dict[x] += 1

        for y in t:
            t_dict[y] += 1

        if s_dict == t_dict:
            return True
        else:
            return False
# @lc code=end

