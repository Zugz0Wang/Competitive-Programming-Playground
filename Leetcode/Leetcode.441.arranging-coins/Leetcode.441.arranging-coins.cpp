/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 *
 * https://leetcode.com/problems/arranging-coins/description/
 *
 * algorithms
 * Easy (45.81%)
 * Likes:    2929
 * Dislikes: 1159
 * Total Accepted:    331.4K
 * Total Submissions: 717.4K
 * Testcase Example:  '5'
 *
 * You have n coins and you want to build a staircase with these coins. The
 * staircase consists of k rows where the i^th row has exactly i coins. The
 * last row of the staircase may be incomplete.
 * 
 * Given the integer n, return the number of complete rows of the staircase you
 * will build.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 5
 * Output: 2
 * Explanation: Because the 3^rd row is incomplete, we return 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 8
 * Output: 3
 * Explanation: Because the 4^th row is incomplete, we return 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    long calculate(int k) {
        return ((long) k * k + k) / 2;
    }
    int arrangeCoins(int n) {
        int head = 1;
        int tail = 65536;
        while (head < tail) {
            int mid_idx = (head + tail) / 2;
            long mid_val = calculate(mid_idx);
            long next_val = calculate(mid_idx + 1);
            if (mid_val <= n && next_val > n) {
                return mid_idx;
            } else if (mid_val < n) {
                head = mid_idx + 1;
            } else {
                tail = mid_idx;
            }
        }//2147483647
        
        return head;
    }
};
// @lc code=end

