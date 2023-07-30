/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 *
 * https://leetcode.com/problems/strange-printer/description/
 *
 * algorithms
 * Hard (46.67%)
 * Likes:    1355
 * Dislikes: 124
 * Total Accepted:    40.5K
 * Total Submissions: 81.3K
 * Testcase Example:  '"aaabbb"'
 *
 * There is a strange printer with the following two special properties:
 * 
 * 
 * The printer can only print a sequence of the same character each time.
 * At each turn, the printer can print new characters starting from and ending
 * at any place and will cover the original existing characters.
 * 
 * 
 * Given a string s, return the minimum number of turns the printer needed to
 * print it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aaabbb"
 * Output: 2
 * Explanation: Print "aaa" first and then print "bbb".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aba"
 * Output: 2
 * Explanation: Print "aaa" first and then print "b" from the second place of
 * the string, which will cover the existing character 'a'.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution { // Learned from solution
public:
    int strangePrinter(string s) {
        size_t size(s.size());
        vector<int> dp_v(size * size, 0);
        int* dp(dp_v.data());
        for (size_t i(size - 1); i < size; --i) {
            dp[i * size + i] = 1;
            for (size_t j(i + 1); j < size; ++j) {
                int& curr(dp[i * size + j]);
                curr = dp[i * size + j - 1] + 1;
                for (size_t k(i); k + 1 < j; ++k) {
                    if (s.at(k) == s.at(j)) {
                        curr = min(curr, dp[i * size + k] + dp[(k + 1) * size + j - 1]);
                    }
                }
                if (s.at(j - 1) == s.at(j)) {
                    curr = min(curr, dp[i * size + j - 1]);
                }
                
            }
        }
        return dp[size - 1];
    }
};
// @lc code=end

