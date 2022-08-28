/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 *
 * https://leetcode.com/problems/reordered-power-of-2/description/
 *
 * algorithms
 * Medium (60.98%)
 * Likes:    653
 * Dislikes: 185
 * Total Accepted:    44.5K
 * Total Submissions: 72.5K
 * Testcase Example:  '1'
 *
 * You are given an integer n. We reorder the digits in any order (including
 * the original order) such that the leading digit is not zero.
 * 
 * Return true if and only if we can do this so that the resulting number is a
 * power of two.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 10
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^9
 * 
 * 
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string n_str = to_string(n);
        sort(n_str.begin(), n_str.end());
        for (int i = 1; i < 1e9; i*=2) {
            string i_str = to_string(i);
            sort(i_str.begin(), i_str.end());
            if (i_str == n_str) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

