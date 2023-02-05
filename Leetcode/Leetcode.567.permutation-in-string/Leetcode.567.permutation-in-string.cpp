/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (44.11%)
 * Likes:    8137
 * Dislikes: 267
 * Total Accepted:    548.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 * 
 * In other words, return true if one of s1's permutations is the substring of
 * s2.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public: // Original Solution
    int count[26];
    bool checkInclusion(string s1, string s2) {
        memset(count, 0, sizeof(count));
        const int kSize1 = s1.size();
        const int kSize2 = s2.size();
        if (kSize1 > kSize2) {
            return false;
        }
        for (int i = 0; i < kSize1; i++) {
            count[s1.at(i) - 'a'] += 1;
            count[s2.at(i) - 'a'] -= 1;
        }
        for (int i = 0; i <= kSize2 - kSize1; i++) {
            bool found = true;
            for (int c = 0; c < 26; c++) {
                if (count[c] != 0) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            } else if (i + kSize1 < kSize2) {
                count[s2.at(i) - 'a'] += 1;
                count[s2.at(i + kSize1) - 'a'] -= 1;
            }
        }
        return false;
    }
};
// @lc code=end

