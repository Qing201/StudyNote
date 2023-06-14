#
# @lc app=leetcode.cn id=59 lang=python3
#
# [59] 螺旋矩阵 II
#

# @lc code=start
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = [ [0] * n for _ in range(n) ]
        num = 1

        for j in range(0,n//2):
            a,b = 0+j, n-1-j
            for i in range(a, b):
                matrix[a][i] = num
                num += 1
            for i in range(a, b):
                matrix[i][b] = num
                num += 1
            for i in range(b,a,-1):
                matrix[b][i] = num
                num += 1
            for i in range(b,a,-1):
                matrix[i][a] = num
                num += 1

        if n%2 != 0:
            matrix[n//2][n//2] = num

        return matrix



        

        


# @lc code=end

