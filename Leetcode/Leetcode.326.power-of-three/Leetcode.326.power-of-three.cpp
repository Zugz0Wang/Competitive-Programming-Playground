/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        
        while (n > 1) {
            int mod = n % 3;
            if (mod > 0) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};
// @lc code=end

