#
# @lc app=leetcode id=232 lang=python3
#
# [232] Implement Queue using Stacks
#

# @lc code=start
class MyQueue:

    def __init__(self):
        self.stackIn = []
        self.stackOut = []

    def push(self, x: int) -> None:
        self.stackIn.append(x)

    def pop(self) -> int:
        if self.empty():
            return True

        if self.stackOut:
            return self.stackOut.pop()
            
        else:
            while self.stackIn:
                self.stackOut.append(self.stackIn.pop())
            return self.stackOut.pop()

    def peek(self) -> int:
        temp = self.pop()
        self.stackOut.append(temp)
        return temp
        
    def empty(self) -> bool:
        if self.stackIn or self.stackOut:
            return False
        else:
            return True


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
# @lc code=end

