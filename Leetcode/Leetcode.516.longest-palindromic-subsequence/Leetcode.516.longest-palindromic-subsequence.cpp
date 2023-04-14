/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (60.23%)
 * Likes:    7146
 * Dislikes: 276
 * Total Accepted:    330.4K
 * Total Submissions: 540.8K
 * Testcase Example:  '"bbbab"'
 *
 * Given a string s, find the longest palindromic subsequence's length in s.
 * 
 * A subsequence is a sequence that can be derived from another sequence by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "bbbab"
 * Output: 4
 * Explanation: One possible longest palindromic subsequence is "bbbb".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "cbbd"
 * Output: 2
 * Explanation: One possible longest palindromic subsequence is "bb".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists only of lowercase English letters.
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int** dp;
    string s;
    int helper(int head, int tail) { // Learned from solution
        int last(tail - 1);
        if (head >= tail) {
            return 0;
        } else if (head + 1 == tail) {
            return 1;
        } else if (dp[head][last] > 0) {
            return dp[head][last];
        }
        
        int curr(0);
        if (s.at(head) == s.at(last)) {
            curr = 2 + helper(head + 1, tail - 1);
        } else {
            int left(helper(head, tail - 1));
            int right(helper(head + 1, tail));
            if (left > right) {
                curr = left;
            } else {
                curr = right;
            }
        }
        dp[head][last] = curr;
        return curr;
    }

    int longestPalindromeSubseq(string _s) {
        const int size(_s.size());
        s = _s;
        dp = new int*[size];
        for (int i(0); i < size; ++i) {
            int* curr(new int[size]);    
            dp[i] = curr;
            for (int j(0); j < size; ++j) {
                curr[j] = 0;
            }
        }

        const int ans(helper(0, size));

        for (int i(0); i < size; ++i) {
           delete[] dp[i];
        }
        delete[] dp;

        return ans;
    }
};
// @lc code=end

