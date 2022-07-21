#
# @lc app=leetcode id=150 lang=python3
#
# [150] Evaluate Reverse Polish Notation
#

# @lc code=start
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        operators = ['+', '-', '*', '/']
        for char in tokens:
            if char == '+':
                stack.append(stack.pop() + stack.pop())
            elif char == '-':
                stack.append(- stack.pop() + stack.pop())
            elif char == '*':
                stack.append(stack.pop() * stack.pop())
            elif char == '/':
                a = stack.pop()
                b = stack.pop()
                stack.append(int(b / a))
            else:
                stack.append(int(char))
        
        return stack[0]


        " Solution 1 "
        " Using eval() "
        # stack = []
        # for item in tokens:
        #     if item not in {"+", "-", "*", "/"}:
        #         stack.append(item)
        #     else:
        #         first_num, second_num = stack.pop(), stack.pop()
        #         stack.append(
        #             int(eval(f'{second_num} {item} {first_num}'))   # 第一个出来的在运算符后面
        #         )
        # return int(stack.pop()) # 如果一开始只有一个数，那么会是字符串形式的



# @lc code=end

