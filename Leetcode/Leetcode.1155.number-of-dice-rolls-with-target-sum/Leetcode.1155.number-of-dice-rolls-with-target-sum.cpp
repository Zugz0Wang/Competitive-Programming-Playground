/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 *
 * https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/
 *
 * algorithms
 * Medium (48.03%)
 * Likes:    2330
 * Dislikes: 91
 * Total Accepted:    118.2K
 * Total Submissions: 245.5K
 * Testcase Example:  '1\n6\n3'
 *
 * You have n dice and each die has k faces numbered from 1 to k.
 * 
 * Given three integers n, k, and target, return the number of possible ways
 * (out of the k^n total ways) to roll the dice so the sum of the face-up
 * numbers equals target. Since the answer may be too large, return it modulo
 * 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1, k = 6, target = 3
 * Output: 1
 * Explanation: You throw one die with 6 faces.
 * There is only one way to get a sum of 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2, k = 6, target = 7
 * Output: 6
 * Explanation: You throw two dice, each with 6 faces.
 * There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 30, k = 30, target = 500
 * Output: 222616187
 * Explanation: The answer must be returned modulo 10^9 + 7.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n, k <= 30
 * 1 <= target <= 1000
 * 
 * 
 */
#include <algorithm>
// @lc code=start
class Solution {
public:
    int dp[35][1005];
    int numRollsToTarget(int n, int k, int target) {
        const int mod = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int num = 1; num <= n; num++) {
            for (int t = 1; t <= target && t <= n * k; t++) {
                for (int face = 1; face <= k; face++) {
                    if (t - face >= 0)
                    dp[num][t] = (dp[num][t] + dp[num - 1][t - face]) % mod;
                }
            }
        }
        return dp[n][target];
    }
};
// @lc code=end

