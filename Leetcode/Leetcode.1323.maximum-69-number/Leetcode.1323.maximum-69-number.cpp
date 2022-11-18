/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 *
 * https://leetcode.com/problems/maximum-69-number/description/
 *
 * algorithms
 * Easy (79.05%)
 * Likes:    1239
 * Dislikes: 133
 * Total Accepted:    128.1K
 * Total Submissions: 161.7K
 * Testcase Example:  '9669'
 *
 * You are given a positive integer num consisting only of digits 6 and 9.
 * 
 * Return the maximum number you can get by changing at most one digit (6
 * becomes 9, and 9 becomes 6).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num = 9669
 * Output: 9969
 * Explanation: 
 * Changing the first digit results in 6669.
 * Changing the second digit results in 9969.
 * Changing the third digit results in 9699.
 * Changing the fourth digit results in 9666.
 * The maximum number is 9969.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = 9996
 * Output: 9999
 * Explanation: Changing the last digit 6 to 9 results in the maximum number.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: num = 9999
 * Output: 9999
 * Explanation: It is better not to apply any change.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num <= 10^4
 * num consists of only 6 and 9 digits.
 * 
 * 
 */
// @lc code=start
class Solution {
public:
    int pow3 (int num) {
        int to_return = 3;
        for (int i = 0; i < num; i++) {
            to_return *= 10;
        }
        return to_return;
    }
    int maximum69Number (int num) {
        int copy_num = num;
        int last_6_idx = -1;
        int count = 0;
        while (copy_num > 0) {
            int digit = copy_num % 10;
            if (digit == 6) {
                last_6_idx = count;
            }
            copy_num /= 10;
            count++;
        }
        if (last_6_idx >= 0) {
            num = num += pow3(last_6_idx);
        }
        return num;
    }
};
// @lc code=end

