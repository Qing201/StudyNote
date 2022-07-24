#
# @lc app=leetcode id=144 lang=python3
#
# [144] Binary Tree Preorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
            
        " Method 1: Recursively 递归"
        # def traversal(root, members):
        #     if root:
        #         members.append(root.val)
        #         if root.left:
        #             traversal(root.left, members)
        #         if root.right:
        #             traversal(root.right, members)

        # result = []
        # traversal(root, result)
        # return result
        

        " Method 2: Iteratively 迭代"
        stack = [root]
        result = []
        while stack:
            node = stack.pop()
            if node:
                result.append(node.val)
                stack.append(node.right)
                stack.append(node.left)

        return result

# @lc code=end

