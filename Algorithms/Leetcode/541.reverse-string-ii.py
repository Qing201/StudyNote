#
# @lc app=leetcode id=541 lang=python3
#
# [541] Reverse String II
#

# @lc code=start
class Solution:
    def reverseStr(self, s: str, k: int) -> str:

        """ Answer 1 """
        # def reverse(str, left, right):
        #     for i in range((right-left+1)//2):
        #         str[left+i], str[right-i] = str[right-i], str[left+i]
        
        # s = list(s)

        # n = len(s)
        # for i in range(n // (2*k)):
        #     reverse(s, i*2*k, i*2*k+k-1)
        
        # remainNum = n % (2*k)
        # if remainNum <=k:
        #     reverse(s, n-remainNum, n-1)
        # else:
        #     reverse(s, n-remainNum, n-remainNum+k-1)

        # return ''.join(s)

        """ Solution""" 
        """ More clever using index """
        def reverse(strList):
            n = len(strList)
            for i in range(n//2):
                strList[i], strList[n-1-i] = strList[n-1-i], strList[i]
            return strList

        s = list(s)

        n = len(s)
        for i in range(0, n-1, 2*k):
            s[i:i+k] = reverse(s[i:i+k])
        
        return ''.join(s)
# @lc code=end

