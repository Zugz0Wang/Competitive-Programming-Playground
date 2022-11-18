/*
 * @lc app=leetcode id=1531 lang=cpp
 *
 * [1531] String Compression II
 *
 * https://leetcode.com/problems/string-compression-ii/description/
 *
 * algorithms
 * Hard (38.31%)
 * Likes:    1225
 * Dislikes: 94
 * Total Accepted:    28.7K
 * Total Submissions: 60.1K
 * Testcase Example:  '"aaabcccd"\n2'
 *
 * Run-length encoding is a string compression method that works by replacing
 * consecutive identical characters (repeated 2 or more times) with the
 * concatenation of the character and the number marking the count of the
 * characters (length of the run). For example, to compress the string "aabccc"
 * we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed
 * string becomes "a2bc3".
 * 
 * Notice that in this problem, we are not adding '1' after single characters.
 * 
 * Given a string s and an integer k. You need to delete at most k characters
 * from s such that the run-length encoded version of s has minimum length.
 * 
 * Find the minimum length of the run-length encoded version of s after
 * deleting at most k characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aaabcccd", k = 2
 * Output: 4
 * Explanation: Compressing s without deleting anything will give us "a3bc3d"
 * of length 6. Deleting any of the characters 'a' or 'c' would at most
 * decrease the length of the compressed string to 5, for instance delete 2 'a'
 * then we will have s = "abcccd" which compressed is abc3d. Therefore, the
 * optimal way is to delete 'b' and 'd', then the compressed version of s will
 * be "a3c3" of length 4.
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aabbaa", k = 2
 * Output: 2
 * Explanation: If we delete both 'b' characters, the resulting compressed
 * string would be "a4" of length 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "aaaaaaaaaaa", k = 0
 * Output: 3
 * Explanation: Since k is zero, we cannot delete anything. The compressed
 * string is "a11" of length 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * 0 <= k <= s.length
 * s contains only lowercase English letters.
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int kLength = 0;
    string str;
    int dp[105][105];
    int INF = 105;

    int digits(int num) {
        if (num <= 1) {
            return 0;
        }
        int count = 0;
        while (num > 0) {
            count++;
            num /= 10;
        }
        return count;
    }

    int helper(int left, int k) {
        if (k < 0) {
            return INF;
        }
        if (left >= kLength || left + k >= kLength) {
            return 0;
        }
        if (dp[left][k] > -1) {
            return dp[left][k];
        }
        int count[26] = {0};
        int res = INF;
        int most = 0;
        for (int i = left; i < kLength; i++) {
            char curr_char = str.at(i);
            int curr_idx = curr_char - 'a';
            most = max(most, ++count[curr_idx]);
            res = min(res, 1 + digits(most) + helper(i + 1, k - (i - left + 1 - most )));
        }
        dp[left][k] = res;
        return res;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        str = s;
        kLength = s.length();
        memset(dp, -1, sizeof(dp));

        return helper(0, k);
    }
};
// @lc code=end

