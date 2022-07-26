#
# @lc app=leetcode id=94 lang=python3
#
# [94] Binary Tree Inorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        
        " Method 1: Recursively 递归"
        # def traversal(root, result):
        #     if root:
        #         traversal(root.left, result)
        #         result.append(root.val)
        #         traversal(root.right, result)
        
        # result = []
        # traversal(root,result)
        # return result


        " Method 2: Iteratively 迭代"
        stack = [root]
        result = []
        while stack:
            stack.append(root)
            if root.left != None:
                root = root.left
                continue
            node = stack.pop()
            if root.right:
            stack.append(root.left)
            root = root.left


        return result
# @lc code=end

