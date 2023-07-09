/*
 * @lc app=leetcode id=2272 lang=cpp
 *
 * [2272] Substring With Largest Variance
 *
 * https://leetcode.com/problems/substring-with-largest-variance/description/
 *
 * algorithms
 * Hard (36.20%)
 * Likes:    1164
 * Dislikes: 148
 * Total Accepted:    38.4K
 * Total Submissions: 91.5K
 * Testcase Example:  '"aababbb"'
 *
 * The variance of a string is defined as the largest difference between the
 * number of occurrences of any 2 characters present in the string. Note the
 * two characters may or may not be the same.
 * 
 * Given a string s consisting of lowercase English letters only, return the
 * largest variance possible among all substrings of s.
 * 
 * A substring is a contiguous sequence of characters within a string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aababbb"
 * Output: 3
 * Explanation:
 * All possible variances along with their respective substrings are listed
 * below:
 * - Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b",
 * "bb", and "bbb".
 * - Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb",
 * "aababbb", and "bab".
 * - Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
 * - Variance 3 for substring "babbb".
 * Since the largest possible variance is 3, we return it.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abcde"
 * Output: 0
 * Explanation:
 * No letter occurs more than once in s, so the variance of every substring is
 * 0.
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
class Solution { // Learned from solution
public:
    int largestVariance(string s) {
        size_t* count(new size_t[26]);
        for (size_t i(0); i < 26; ++i) {
            count[i] = 0;
        }
        for (char c : s) {
            count[c - 'a'] += 1;
        }
        int ans(0);
        const size_t size(s.size());
        for (char c1('a'); c1 <= 'z'; ++c1) {
            for (char c2('a'); c2 <= 'z'; ++c2) {
                if (c1 == c2 || count[c1 - 'a'] == 0 || count[c2 - 'a'] == 0) {
                    continue;
                }

                int count1(0);
                int count2(0);
                for (size_t i(0); i < size; ++i) {
                    char curr(s.at(i));
                    if (curr == c1) {
                        count1 += 1;
                    } else if (curr == c2) {
                        count2 += 1;
                    }
                    if (count1 > 1 && count2 > 0 && count1 - count2 > ans) {
                        ans = count1 - count2;
                    }
                    if (count2 > count1) {
                        count1 = 0;
                        count2 = 0;
                    }
                }

                count1 = 0;
                count2 = 0;
                for (size_t i(0); i < size; ++i) {
                    char curr(s.at(size - i - 1));
                    if (curr == c1) {
                        count1 += 1;
                    } else if (curr == c2) {
                        count2 += 1;
                    }
                    if (count1 > 0 && count2 > 0 && count1 -count2 > ans) {
                       ans = count1 - count2;
                    }
                    if (count2 > count1) {
                        count1 = 0;
                        count2 = 0;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

