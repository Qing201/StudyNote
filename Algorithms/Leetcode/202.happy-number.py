#
# @lc app=leetcode id=202 lang=python3
#
# [202] Happy Number
#

# @lc code=start
class Solution:
    def isHappy(self, n: int) -> bool:
        
        def digitsSquares(num):
            new_num = 0
            while num > 0:
                new_num += (num % 10) ** 2
                num //= 10
            return new_num
        
        pastNums = {n}
        while n != 1:
            n = digitsSquares(n)
            if n in pastNums:
                return False
            pastNums.add(n)
        
        return True


# @lc code=end

