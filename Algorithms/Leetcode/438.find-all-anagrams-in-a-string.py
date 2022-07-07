#
# @lc app=leetcode id=438 lang=python3
#
# [438] Find All Anagrams in a String
#

# @lc code=start
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        
        indexes = []

        if len(s) < len(p):
            return indexes

        p_hash = [0] * 26
        for char in p:
            p_hash[ord(char) - ord('a')] += 1
        
        window_hash = [0] * 26

        for i in range(len(p)):
            window_hash[ord(s[i]) - ord('a')] += 1
        
        if window_hash == p_hash:
            indexes.append(0)

        for i in range(len(s)-len(p)):
            window_hash[ord(s[i]) - ord('a')] -= 1
            window_hash[ord(s[i+len(p)]) - ord('a')] += 1
            if window_hash == p_hash:
                indexes.append(i+1)

        return indexes

        
# @lc code=end

