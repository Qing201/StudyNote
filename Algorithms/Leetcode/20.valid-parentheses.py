#
# @lc app=leetcode id=20 lang=python3
#
# [20] Valid Parentheses
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for char in s:
            if char == "{": 
                stack.append("}")
            elif char == "[": 
                stack.append("]")
            elif char == "(": 
                stack.append(")")
            
            else:
                if stack and stack.pop() == char:
                    pass
                else:
                    return False
                    
        if stack:
            return False
        else:
            return True


# @lc code=end

