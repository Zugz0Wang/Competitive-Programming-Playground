/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (52.16%)
 * Likes:    7792
 * Dislikes: 339
 * Total Accepted:    582.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '12'
 *
 * Given an integer n, return the least number of perfect square numbers that
 * sum to n.
 * 
 * A perfect square is an integer that is the square of an integer; in other
 * words, it is the product of some integer with itself. For example, 1, 4, 9,
 * and 16 are perfect squares while 3 and 11 are not.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */
#include <math.h>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int mem[10001];
    int helper(int n) {
        if (mem[n] > 0) {
            return mem[n];
        }
        if (n == 0) {
            return 0;
        }
        int min = 0;
        bool flag = false;
        for (int i = 1; i * i <= n; i++) {
            int curr = helper(n - i * i);
            //cout << curr << '\n';
            if (flag) {
                if (curr < min) {
                    min = curr;
                }
            } else {
                min = curr;
                flag = true;
            }
        }
        mem[n] = min + 1;
        return min + 1;
    }
    int numSquares(int n) {
        memset(mem, 0, sizeof(mem));
        return helper(n);
    }
};
// @lc code=end

