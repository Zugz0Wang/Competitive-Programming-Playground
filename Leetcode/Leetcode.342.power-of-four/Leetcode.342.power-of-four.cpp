/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }
        
        while (n > 1) {
            int mod = n & 3; // The last two bits, if two zero, it can be divided by 4
            if (mod > 0) {
                return false;
            }
            n = n >> 2;
        }
        return true;
    }
};
// @lc code=end

