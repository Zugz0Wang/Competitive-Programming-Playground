/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Medium (36.87%)
 * Likes:    7639
 * Dislikes: 435
 * Total Accepted:    450.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given strings s1, s2, and s3, find whether s3 is formed by an interleaving
 * of s1 and s2.
 * 
 * An interleaving of two strings s and t is a configuration where s and t are
 * divided into n and m substrings respectively, such that:
 * 
 * 
 * s = s1 + s2 + ... + sn
 * t = t1 + t2 + ... + tm
 * |n - m| <= 1
 * The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 +
 * t3 + s3 + ...
 * 
 * 
 * Note: a + b is the concatenation of strings a and b.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 * Explanation: One way to obtain s3 is:
 * Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
 * Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" =
 * "aadbbcbcac".
 * Since s3 can be obtained by interleaving s1 and s2, we return true.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 * Explanation: Notice how it is impossible to interleave s2 with any other
 * string to obtain s3.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s1 = "", s2 = "", s3 = ""
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s1.length, s2.length <= 100
 * 0 <= s3.length <= 200
 * s1, s2, and s3 consist of lowercase English letters.
 * 
 * 
 * 
 * Follow up: Could you solve it using only O(s2.length) additional memory
 * space?
 * 
 */

// @lc code=start
class Solution { // Learned from solution
public:
    bool isInterleave(string s1, string s2, string s3) {
        size_t s1_size(s1.size());
        size_t s2_size(s2.size());
        size_t s3_size(s3.size());
        if (s1_size + s2_size != s3_size) return false;

        if (s1_size < s2_size) {
            swap(s1, s2);
            swap(s1_size, s2_size);
        }

        vector<bool> dp(s2_size + 1, false);
        dp.at(0) = true;

        for (size_t j(1); j <= s2_size; ++j) {
            dp.at(j) = dp.at(j - 1) && s2.at(j - 1) == s3.at(j - 1);
        }

        for (size_t i(1); i <= s1_size; ++i) {
            dp.at(0) = dp.at(0) && s1.at(i - 1) == s3.at(i - 1);
            for (size_t j(1); j <= s2_size; ++j) {
                // dp.at(j) is actually the previous row
                dp.at(j) = (dp.at(j - 1) && s2.at(j - 1) == s3.at(i + j - 1)) || (dp.at(j) && s1.at(i - 1) == s3.at(i + j - 1));
                
            }
        }   

        return dp.at(s2_size);
    }
};
// @lc code=end

