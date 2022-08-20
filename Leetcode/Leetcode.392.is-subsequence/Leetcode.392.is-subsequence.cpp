/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 *
 * https://leetcode.com/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (50.19%)
 * Likes:    5537
 * Dislikes: 319
 * Total Accepted:    565.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * Given two strings s and t, return true if s is a subsequence of t, or false
 * otherwise.
 * 
 * A subsequence of a string is a new string that is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (i.e., "ace" is a
 * subsequence of "abcde" while "aec" is not).
 * 
 * 
 * Example 1:
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 * Example 2:
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 100
 * 0 <= t.length <= 10^4
 * s and t consist only of lowercase English letters.
 * 
 * 
 * 
 * Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k
 * >= 10^9, and you want to check one by one to see if t has its subsequence.
 * In this scenario, how would you change your code?
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int sLength = s.length() + 1;
        const int tLength = t.length() + 1;
        
        vector<bool> row(tLength, false);
        vector<vector<bool>> dp_table(sLength, row);
        // s[0] means the substring of length 0 of s from the head
        // so the dp_table[1][1] should check whether the char at index 0 matches.
        // s[i] == t[j] dp[i][j] = dp[i - 1][j - 1]
        // s[i] != t[j] dp[i][j] = s[i][j - 1];
        for (int i = 0; i < tLength; i++) {
            dp_table.at(0).at(i) = true;
        }
        for (int i = 1; i < sLength; i++) {
            for (int j = 1; j < tLength; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp_table.at(i).at(j) = dp_table.at(i - 1).at(j - 1);
                } else {
                    dp_table.at(i).at(j) = dp_table.at(i).at(j - 1);
                }
            }
        }
        return dp_table.at(sLength - 1).at(tLength - 1);
    }
};
// @lc code=end