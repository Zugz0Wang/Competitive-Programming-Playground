/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (32.63%)
 * Likes:    5397
 * Dislikes: 6067
 * Total Accepted:    999K
 * Total Submissions: 3.1M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (i.e.,
 * x^n).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 2.00000, n = 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = 2.10000, n = 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: x = 2.00000, n = -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * -10^4 <= x^n <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        
        bool negative = false;
        long num = n;
        if (n < 0) {
            num = -num;
            negative =true;
        }

        double answer = 1;
        double x_pow = x;
        while (num > 0) {
            if (num & 1 == 1) {
                answer *= x_pow;
            }
            x_pow *= x_pow;
            num = num >> 1;
        }

        if (negative) {
            return 1 / answer;
        } else {
            return answer;
        }
    }
};
// @lc code=end

