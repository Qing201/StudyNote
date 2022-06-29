#
# @lc app=leetcode id=69 lang=python3
#
# [69] Sqrt(x)
#

# @lc code=start

class Solution:
    def mySqrt(self, x: int) -> int:
        left, right = 0, x
        while left <= right:
            mid = (right + left) // 2
            num = mid * mid 
            if num > x: 
                right = mid - 1
            elif num < x:
                left = mid + 1
            else:
                return mid

        return left - 1 
                

# @lc code=end

