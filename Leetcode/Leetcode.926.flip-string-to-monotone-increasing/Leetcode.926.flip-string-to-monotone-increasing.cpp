/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 *
 * https://leetcode.com/problems/flip-string-to-monotone-increasing/description/
 *
 * algorithms
 * Medium (59.47%)
 * Likes:    2387
 * Dislikes: 106
 * Total Accepted:    112K
 * Total Submissions: 187.5K
 * Testcase Example:  '"00110"'
 *
 * A binary string is monotone increasing if it consists of some number of 0's
 * (possibly none), followed by some number of 1's (also possibly none).
 * 
 * You are given a binary string s. You can flip s[i] changing it from 0 to 1
 * or from 1 to 0.
 * 
 * Return the minimum number of flips to make s monotone increasing.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "00110"
 * Output: 1
 * Explanation: We flip the last digit to get 00111.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "010110"
 * Output: 2
 * Explanation: We flip to get 011111, or alternatively 000111.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "00011000"
 * Output: 2
 * Explanation: We flip to get 00000000.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] is either '0' or '1'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int min(int a, int b) {
        if (a < b) {
            return a;
        } else {
            return b;
        }
    }
    int minFlipsMonoIncr(string s) {
        int count_one = 0;
        int count_flip = 0;
        for (char c : s) {
            if (c == '1') {
                count_one += 1;
            } else {
                count_flip += 1;
            }
            count_flip = min(count_flip, count_one);
        }
        return count_flip;
    }
};
// @lc code=end

