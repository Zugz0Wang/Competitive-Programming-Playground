/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */
#include <unordered_set>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> numbers;
        bool to_return = true;
        while (n != 1) {
            if (numbers.count(n) != 0) { // If looping back to an previous state
                to_return = false; // Then it's not a happy number
                break;
            }
            numbers.insert(n);
            int new_number = 0;
            while (n > 0) {
                int mod = n % 10; // Extracting each digit
                new_number += mod * mod; // Power of 2
                n = n / 10;
            }
            n = new_number;
            // cout << n << ' ';
        }
        return to_return;
    }
};
// @lc code=end

