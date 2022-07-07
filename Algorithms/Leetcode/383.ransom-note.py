#
# @lc app=leetcode id=383 lang=python3
#
# [383] Ransom Note
#

# @lc code=start
from typing import Counter


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:

        ''' Answer 1 '''
        ''' Using collections.Counter '''
        # from collections import Counter
        # ransom_counter = Counter(ransomNote)
        # magazine_counter = Counter(magazine)

        # for char in ransom_counter:
        #     if not magazine_counter[char] or magazine_counter[char] < ransom_counter[char]:
        #         return False
        
        # return True
        
        ''' Answer 2 '''
        ''' defaultdict '''
        # from collections import defaultdict

        # char_dict = defaultdict(int)

        # for char in magazine:
        #     char_dict[char] += 1
        # for char in ransomNote:
        #     char_dict[char] -= 1
        #     if char_dict[char] < 0:
        #         return False

        # return True
        
        ''' Answer 2 '''
        char_dict = [0] * 26

        for char in magazine:
            char_dict[ord(char) - ord('a')] += 1

        for char in ransomNote:
            char_dict[ord(char) - ord('a')] -= 1

        for num in char_dict:
            if num < 0:
                return False
        
        return True
        
# @lc code=end

