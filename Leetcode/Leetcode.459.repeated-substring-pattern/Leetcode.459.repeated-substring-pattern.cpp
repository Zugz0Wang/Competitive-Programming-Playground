/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (43.69%)
 * Likes:    4680
 * Dislikes: 421
 * Total Accepted:    316.3K
 * Total Submissions: 720.3K
 * Testcase Example:  '"abab"'
 *
 * Given a string s, check if it can be constructed by taking a substring of it
 * and appending multiple copies of the substring together.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abab"
 * Output: true
 * Explanation: It is the substring "ab" twice.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aba"
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "abcabcabcabc"
 * Output: true
 * Explanation: It is the substring "abc" four times or the substring "abcabc"
 * twice.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved
public:
    bool repeatedSubstringPattern(string s) {
        const size_t size(s.size());

        for (size_t length(1); length <= size / 2; ++length) {
            if (size % length > 0) {
                continue;
            }
            const string curr(s.substr(0, length));
            bool flag(true);
            for (size_t i(1); (i * length + length) <= size; ++i) {
                if (s.substr(i * length, length) != curr) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

