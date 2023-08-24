/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size() - 1;
        int fast = 0;
        int slow = 0;
        while (fast <= len) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                if (slow != fast) {
                    nums[fast] = 0;
                }
                slow ++;
            }
            fast ++;
        }
    }
};
// @lc code=end

