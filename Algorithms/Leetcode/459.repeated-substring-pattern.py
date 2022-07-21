#
# @lc app=leetcode id=459 lang=python3
#
# [459] Repeated Substring Pattern
#

# @lc code=start
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        if s in (s+s)[1: -1]:
            return True
        else:
            return False
# @lc code=end

