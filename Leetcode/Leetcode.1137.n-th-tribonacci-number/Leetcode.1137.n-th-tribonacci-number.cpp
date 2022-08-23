/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 *
 * https://leetcode.com/problems/n-th-tribonacci-number/description/
 *
 * algorithms
 * Easy (63.28%)
 * Likes:    2134
 * Dislikes: 120
 * Total Accepted:    323.7K
 * Total Submissions: 511.5K
 * Testcase Example:  '4'
 *
 * The Tribonacci sequence Tn is defined as follows: 
 * 
 * T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
 * 
 * Given n, return the value of Tn.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: 4
 * Explanation:
 * T_3 = 0 + 1 + 1 = 2
 * T_4 = 1 + 1 + 2 = 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 25
 * Output: 1389537
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 37
 * The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31
 * - 1.
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        } else if (n <= 2) {
            return 1;
        }
        vector<unsigned int> dp_table(n + 1, 0);
        dp_table.at(1) = 1;
        dp_table.at(2) = 1;
        for (int i = 3; i <= n; i++) {
            dp_table.at(i) = dp_table.at(i - 1) + dp_table.at(i - 2) + dp_table.at(i - 3);
        }
        return dp_table.at(n);
    }
};
// @lc code=end

