/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 *
 * https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
 *
 * algorithms
 * Medium (61.96%)
 * Likes:    3670
 * Dislikes: 93
 * Total Accepted:    126.7K
 * Total Submissions: 195K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * Given two strings s1 and s2, return the lowest ASCII sum of deleted
 * characters to make two strings equal.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "sea", s2 = "eat"
 * Output: 231
 * Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to
 * the sum.
 * Deleting "t" from "eat" adds 116 to the sum.
 * At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum
 * possible to achieve this.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "delete", s2 = "leet"
 * Output: 403
 * Explanation: Deleting "dee" from "delete" to turn the string into "let",
 * adds 100[d] + 101[e] + 101[e] to the sum.
 * Deleting "e" from "leet" adds 101[e] to the sum.
 * At the end, both strings are equal to "let", and the answer is
 * 100+101+101+101 = 403.
 * If instead we turned both strings into "lee" or "eet", we would get answers
 * of 433 or 417, which are higher.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s1.length, s2.length <= 1000
 * s1 and s2 consist of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution { // Hinted from hints
public:
    size_t n;
    size_t m;
    int* dp;
    size_t index(size_t i, size_t j) {
        return i * (m + 1) + j;
    }
    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        vector<int> dp_v((n + 1) * (m + 1), 0);
        dp = dp_v.data();

        for (size_t i(1); i <= n; ++i) {
            dp[index(i, 0)] = dp[index(i - 1, 0)] + (int)s1.at(i - 1);
        }
        for (size_t j(1); j <= m; ++j) {
            dp[index(0, j)] = dp[index(0, j - 1)] + (int)s2.at(j - 1);
        }
        for (size_t i(1); i <= n; ++i) {
            for (size_t j(1); j <= m; ++j) {
                int& curr(dp[index(i, j)]);
                if (s1.at(i - 1) == s2.at(j - 1)) {
                    curr = dp[index(i - 1, j - 1)];
                } else {
                    curr = min(dp[index(i - 1, j)] + (int)s1.at(i - 1), dp[index(i, j - 1)] + (int)s2.at(j - 1));
                }
            }
        }
        return dp[index(n, m)];
    }
};
// @lc code=end

