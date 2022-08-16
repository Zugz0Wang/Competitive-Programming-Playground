/*
 * @lc app=leetcode id=292 lang=cpp
 *
 * [292] Nim Game
 */

// @lc code=start
class Solution {
public:
    // DP: 1 1 1 0 1 1 1 0 1 1 1 0
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
// @lc code=end

