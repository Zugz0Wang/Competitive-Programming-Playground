/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (40.87%)
 * Likes:    4790
 * Dislikes: 364
 * Total Accepted:    348.4K
 * Total Submissions: 831.9K
 * Testcase Example:  '"1 + 1"'
 *
 * Given a string s representing a valid expression, implement a basic
 * calculator to evaluate it, and return the result of the evaluation.
 * 
 * Note: You are not allowed to use any built-in function which evaluates
 * strings as mathematical expressions, such as eval().
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "1 + 1"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = " 2-1 + 2 "
 * Output: 3
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s consists of digits, '+', '-', '(', ')', and ' '.
 * s represents a valid expression.
 * '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is
 * invalid).
 * '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is
 * valid).
 * There will be no two consecutive operators in the input.
 * Every number and running calculation will fit in a signed 32-bit integer.
 * 
 * 
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        const int kLength = s.size();
        vector<bool> signs(2, true);
        for (int i = 0; i < kLength; i++) {
            char c = s.at(i);
            if (c >= '0') {
                int number = 0;
                do {
                    c = s.at(i);
                    number = number * 10 + (c - '0');
                    i++;
                } while (i < kLength && s.at(i) >= '0');
                if (signs.back()) {
                    ans += number;
                } else {
                    ans -= number;
                }
                signs.pop_back();
                i--;
            } else if (c == ')') {
                signs.pop_back();
            } else if (c != ' ') {
                // cout << c << '\n';
                bool back = signs.back();
                if (back) {
                    if (c == '-') {
                        signs.push_back(false);
                    } else if (c == '(') {
                        if (i + 1 < kLength && s.at(i + 1) >= '0') {
                            signs.push_back(true);//'"-(-2)"'
                        }
                    } else {
                        signs.push_back(true);
                    }
                } else {
                    if (c == '-') {
                        signs.push_back(true);
                    } else if (c == '(') {
                        if (i + 1 < kLength && s.at(i + 1) >= '0') {
                            signs.push_back(false);//'"-(-2)"'
                        }
                    } else {
                        signs.push_back(false);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

