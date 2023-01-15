/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Medium (34.74%)
 * Likes:    1925
 * Dislikes: 505
 * Total Accepted:    160.7K
 * Total Submissions: 465.4K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer c, decide whether there're two integers a and b
 * such that a^2 + b^2 = c.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: c = 5
 * Output: true
 * Explanation: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: c = 3
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= c <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        int head = 0;
        int tail = 46341;
        while (head <= tail) {
            long mid_val = (long) head * head + (long) tail * tail;
            if (mid_val == c) {
                return true;
            } else if (mid_val > c) {
                tail--;
            } else {
                head++;
            }
            
        }
        
        return false;
    }
};
// @lc code=end

