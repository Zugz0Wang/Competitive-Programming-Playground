/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (43.20%)
 * Likes:    2733
 * Dislikes: 249
 * Total Accepted:    407K
 * Total Submissions: 941.7K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * Follow up: Do not use any built-in library function such as sqrt.
 * 
 * 
 * Example 1:
 * Input: num = 16
 * Output: true
 * Example 2:
 * Input: num = 14
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }
        int head = 1;
        int tail = num / 2;
        while (head <= tail) {
            int mid = (head + tail) / 2;
            int val = num / mid;
            if (val == mid && num % mid == 0) {
                return true;
            } else if (val > mid) {
                head = mid + 1;
            } else {
                tail = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end

