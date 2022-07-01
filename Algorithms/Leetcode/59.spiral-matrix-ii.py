#
# @lc app=leetcode id=59 lang=python3
#
# [59] Spiral Matrix II
#

# @lc code=start
from logging import logProcesses


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        
        matrix = [ [0] * n for _ in range(n) ]

        num = 1

        for loop in range(n//2):
            i, j = loop, loop
            # right
            while j <= n-loop-2:
                matrix[i][j] = num
                j += 1
                num += 1
            # down
            while i <= n-loop-2:
                matrix[i][j] = num
                i += 1
                num += 1
            # left
            while j >= loop+1:
                matrix[i][j] = num
                j -= 1
                num += 1
            # up
            while i >= loop+1:
                matrix[i][j] = num
                i -= 1
                num += 1


        if n%2 == 1:
            matrix[n//2][n//2] = num

        return matrix

# @lc code=end

