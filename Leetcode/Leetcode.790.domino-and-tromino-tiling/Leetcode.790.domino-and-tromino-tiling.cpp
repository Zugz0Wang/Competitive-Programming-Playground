/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 *
 * https://leetcode.com/problems/domino-and-tromino-tiling/description/
 *
 * algorithms
 * Medium (48.23%)
 * Likes:    1869
 * Dislikes: 665
 * Total Accepted:    58.5K
 * Total Submissions: 119.4K
 * Testcase Example:  '3'
 *
 * You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You
 * may rotate these shapes.
 * 
 * Given an integer n, return the number of ways to tile an 2 x n board. Since
 * the answer may be very large, return it modulo 10^9 + 7.
 * 
 * In a tiling, every square must be covered by a tile. Two tilings are
 * different if and only if there are two 4-directionally adjacent cells on the
 * board such that exactly one of the tilings has both squares occupied by a
 * tile.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output: 5
 * Explanation: The five different ways are show above.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 1000
 * 
 * 
 */
#include <vector>
// @lc code=start
class Solution {
public:
    long dp[4];
    const int kMod = 1e9 + 7;
    int numTilings(int n) {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        int i = 2;
        int head = 2;
        if (n <= head) {
            return dp[n];
        }
        while (i < n) {
            head = (head + 1) % 4;
            dp[head] = (dp[(head + 3) % 4] * 2 + dp[(head + 1) % 4]) % kMod;
            i++;
        }

        return dp[head];
    }
};
// @lc code=end

