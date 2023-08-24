/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        int len = nums.size() - 1;

        while (fast <= len) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast ++;
        }
        return ++slow;
    }
};
// @lc code=end

