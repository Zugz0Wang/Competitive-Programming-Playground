/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        
        while (n > 1) {
            int mod = n % 2;
            if (mod == 1) {
                return false;
            }
            n /= 2;
        }
        return true;
    }
};
// @lc code=end

