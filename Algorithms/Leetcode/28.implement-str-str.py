#
# @lc app=leetcode id=28 lang=python3
#
# [28] Implement strStr()
#

# @lc code=start
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:

        def needleCount(needleStr):
            needle_count = [0] * len(needle)
            left, right = 0, 1
            while right < len(needle):
                if needle[right] == needle[left]:
                    needle_count[right] = left+1
                    left += 1
                    right += 1
                elif left == 0:
                    needle_count[right] = 0
                    right += 1
                else:
                    left = needle_count[left-1]
            return needle_count

        needle_count = needleCount(needle)

        n_h = len(haystack)
        if n_h == 0:
            return 0

        n_n = len(needle)
        haystack_index, needle_index = 0, 0

        while needle_index < n_n:
            if haystack_index == n_h:
                return -1

            if haystack[haystack_index] == needle[needle_index]:
                haystack_index += 1
                needle_index += 1
            else:
                if needle_index == 0:
                    haystack_index += 1
                else:
                    needle_index = needle_count[needle_index-1]

        else:
            return haystack_index - n_n


    


# @lc code=end

