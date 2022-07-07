#
# @lc app=leetcode id=1002 lang=python3
#
# [1002] Find Common Characters
#

# @lc code=start


class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        
        '''Answer 1'''

        # record_min =  [0] * 26
        # char_list = []

        # if words[0]:
        #     word = words[0]
        #     for char in word:
        #         record_min[ord(char) - ord("a")] += 1
        # else:
        #     return char_list
            
        # for word in words:
        #     record_word = [0] * 26
        #     for char in word:
        #         record_word[ord(char) - ord("a")] += 1
        #     for i in range(26):
        #         record_min[i] = min(record_min[i], record_word[i])
        
        # for index in range(26):
        #     for _ in range(record_min[index]):
        #         char_list.append(chr(index + ord("a")))
        
        # return char_list


        '''Answer 2'''
        from collections import Counter
        char_list = []

        if words[0]:
            record_min = Counter(words[0])
        
        for i in range(1, len(words)):
            record_temp = Counter(words[i])
            record_min = record_min & record_temp
        
        for word in record_min:
            for _ in range(record_min[word]):
                char_list.append(word)
        
        return char_list
                
    
# @lc code=end

