/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 *
 * https://leetcode.com/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (58.94%)
 * Likes:    9016
 * Dislikes: 103
 * Total Accepted:    572.2K
 * Total Submissions: 974.1K
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * Given two strings text1 and text2, return the length of their longest common
 * subsequence. If there is no common subsequence, return 0.
 * 
 * A subsequence of a string is a new string generated from the original string
 * with some characters (can be none) deleted without changing the relative
 * order of the remaining characters.
 * 
 * 
 * For example, "ace" is a subsequence of "abcde".
 * 
 * 
 * A common subsequence of two strings is a subsequence that is common to both
 * strings.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: text1 = "abcde", text2 = "ace" 
 * Output: 3  
 * Explanation: The longest common subsequence is "ace" and its length is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: text1 = "abc", text2 = "abc"
 * Output: 3
 * Explanation: The longest common subsequence is "abc" and its length is 3.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: text1 = "abc", text2 = "def"
 * Output: 0
 * Explanation: There is no such common subsequence, so the result is 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= text1.length, text2.length <= 1000
 * text1 and text2 consist of only lowercase English characters.
 * 
 * 
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    short dp[1002][1002];
    int max(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, 0, sizeof(dp));
        const int l1 = text1.size();
        const int l2 = text2.size();
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                
                if (text1.at(i) == text2.at(j)) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
                // cout << dp[i + 1][j + 1] << ' ';
            }
            //cout << '\n';
        }
        return dp[l1][l2];
    }
};
// @lc code=end

