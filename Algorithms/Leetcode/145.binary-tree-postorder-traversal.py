#
# @lc app=leetcode id=145 lang=python3
#
# [145] Binary Tree Postorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        
        " Method 1: Recursively 递归"
        # def traversal(root, result):
        #     if root:
        #         traversal(root.left, result)
        #         traversal(root.right, result)
        #         result.append(root.val)
        
        # result = []
        # traversal(root,result)
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

        return result[::-1]


# @lc code=end

