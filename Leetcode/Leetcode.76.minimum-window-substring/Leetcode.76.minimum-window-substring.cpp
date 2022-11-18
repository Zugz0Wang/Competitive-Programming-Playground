/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (39.63%)
 * Likes:    13170
 * Dislikes: 579
 * Total Accepted:    901.1K
 * Total Submissions: 2.2M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t of lengths m and n respectively, return the
 * minimum window substring of s such that every character in t (including
 * duplicates) is included in the window. If there is no such substring, return
 * the empty string "".
 * 
 * The testcases will be generated such that the answer is unique.
 * 
 * A substring is a contiguous sequence of characters within the string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
 * from string t.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "a", t = "a"
 * Output: "a"
 * Explanation: The entire string s is the minimum window.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "a", t = "aa"
 * Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s and t consist of uppercase and lowercase English letters.
 * 
 * 
 * 
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:

    int remain[52] = {0};
    
    inline int charIndex(char c) {
        if (c >= 'a') {
            return 26 + (c - 'a');
        } else {
            return c - 'A';
        }
    }
    string minWindow(string s, string t) {
        int need = t.length();
        const int kSize = s.length();
        if (need > kSize) {
            return "";
        }
        for (char c : t) {
            remain[charIndex(c)]++;
        }
        
        int lower = 0;
        int upper = 0;
        
        bool found = false;
        int min_len = 0;
        int min_idx = 0;
        while (lower < kSize && upper <= kSize) {
            
            if (need > 0) {

                if (upper == kSize) break;
                char upper_char = s.at(upper);
                
                int upper_idx = charIndex(upper_char);
                remain[upper_idx]--;
                if (remain[upper_idx] >= 0) {
                    need--;
                }

                upper++;

            } else {
                char lower_char = s.at(lower);
                int curr_len = upper - lower;
                if (found && curr_len < min_len) {
                    min_len = curr_len;
                    min_idx = lower;
                } else if (!found) {
                    found = true;
                    min_len = curr_len;
                    min_idx = lower;
                }
                int lower_idx = charIndex(lower_char);
                remain[lower_idx]++;
                if (remain[lower_idx] > 0) {
                    need++;
                }

                lower++;

            }
        }
        if (found) {
            return s.substr(min_idx, min_len);
        } else {
            return "";
        }
    }
};
// @lc code=end

