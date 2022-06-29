#
# @lc app=leetcode id=844 lang=python3
#
# [844] Backspace String Compare
#

# @lc code=start

class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        s_chars = [char for char in s]
        t_chars = [char for char in t]

        self.removeChars(s_chars)
        self.removeChars(t_chars)

        if s_chars == t_chars:
            return True
        else:
            return False

    def removeChars(self, stringList):
        i = 0
        while i < len(stringList):
            if stringList[i] == '#':
                if i == 0:
                    del stringList[0]
                else:
                    del stringList[i], stringList[i-1]
                    i -= 1  
            else:
                i += 1


# @lc code=end

