/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
// For any natrual number, adding a 9 doesn't change its sum of digit mod 9.
// If the last digit = 0, sum of digit += 9, mod 9 doesn't change.
// If the last digit != 0, the digit -= 1, carry += 1 (if 9, sum of digit -= 9, still), mod 9 doesn't change.
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        }
        int mod = num % 9;
        if (mod == 0) {
            return 9;
        } else {
            return mod;
        }
    }
};
// @lc code=end

