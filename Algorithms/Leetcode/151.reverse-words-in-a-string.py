#
# @lc app=leetcode id=151 lang=python3
#
# [151] Reverse Words in a String
#

# @lc code=start


class Solution:
    def reverseWords(self, s: str) -> str:
        
        def removeSpace(s):
            left, right = 0, 0
            n = len(s) - 1
            while s[right] == ' ':
                right += 1
            while s[n] == ' ':
                n -= 1

            while right <= n:
                if s[right] == ' ' and s[right-1] == ' ':
                    right +=1
                else:
                    s[left] = s[right]
                    right += 1
                    left += 1
            return s[:left]
                


        def reverseString(s):
            n = len(s)
            for i in range(n//2):
                s[i], s[n-1-i] = s[n-1-i], s[i]

        def reverseWord(s):
            left, right = 0, 0
            n = len(s) - 1

            while right <= n:
                if right == n or s[right+1] == ' ':
                    for i in range((right - left + 1)//2):
                        s[right-i], s[left+i] = s[left+i], s[right-i]
                    right += 2
                    left = right
                else:
                    right += 1

        s = list(s)
        s = removeSpace(s)
        reverseString(s)
        reverseWord(s)

        return ''.join(s)
        
# @lc code=end

