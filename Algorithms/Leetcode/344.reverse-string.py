#
# @lc app=leetcode id=344 lang=python3
#
# [344] Reverse String
#

# @lc code=start
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        n = len(s)
        for i in range(n//2):
            # temp = s[i]
            # s[i] = s[n-i]
            # s[n-i] = temp
            s[i], s[n-1-i] = s[n-1-i], s[i]

            

# @lc code=end

