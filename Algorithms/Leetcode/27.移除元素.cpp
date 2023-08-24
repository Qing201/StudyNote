/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        int quick = 0;
        int len = nums.size() - 1;
        while (quick <= len)
        {
            if (nums[quick] == val) {
                quick++;
            } else {
                nums[slow] = nums[quick];
                slow++;
                quick++;
            }
        }
        return slow;
        
    }
};
// @lc code=end

