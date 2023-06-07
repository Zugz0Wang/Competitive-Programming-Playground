/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 *
 * https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/
 *
 * algorithms
 * Medium (65.73%)
 * Likes:    753
 * Dislikes: 54
 * Total Accepted:    38.3K
 * Total Submissions: 56.3K
 * Testcase Example:  '2\n6\n5'
 *
 * Given 3 positives numbers a, b and c. Return the minimum flips required in
 * some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
 * Flip operation consists of change any single bit 1 to 0 or change the bit 0
 * to 1 in their binary representation.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: a = 2, b = 6, c = 5
 * Output: 3
 * Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
 * 
 * Example 2:
 * 
 * 
 * Input: a = 4, b = 2, c = 7
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: a = 1, b = 2, c = 3
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= a <= 10^9
 * 1 <= b <= 10^9
 * 1 <= c <= 10^9
 * 
 */

// @lc code=start
class Solution {
public:
    int minFlips(int a, int b, int c) { // Independently solved
        size_t s(0);
        int count(0);
        while (a > 0 || b > 0 || c > 0) {
            s = 0;
            if ((a & 1) == 1) {
                s = s | 1;
            }
            if ((b & 1) == 1) {
                s = s | 2;
            }
            if ((c & 1) == 1) {
                s = s | 4;
            }
            if (s == 3) {
                count += 2;
            } else if (s == 1 || s == 2 || s == 4) {
                count += 1;
            }
            // cout << s << ' ' << count << '\n';
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
            // 000 0 0
            // 001 1 1
            // 010 2 1
            // 011 3 2
            // 100 4 2
            // 101 5 0
            // 110 6 0
            // 111 7 1
        }
        return count;
    }
};
// @lc code=end

