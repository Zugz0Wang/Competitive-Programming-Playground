/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        int to_return = 0;
        if (x == -2147483648) { // The only case can't turn to positive
            return 0;
        }
        if (x < 0) {
            negative = true;
            x = -x;
        }
        while (x > 0) {
            int mod = x % 10;
            if (to_return < 214748365) {
                to_return *= 10;
                to_return += mod;
            } else {
                return 0;
            }
            x /= 10;
        }
        if (negative) {
            to_return = -to_return;
        }
        return to_return;
    }
};
// @lc code=end

