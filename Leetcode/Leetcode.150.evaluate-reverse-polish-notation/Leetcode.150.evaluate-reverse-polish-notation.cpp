/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (43.75%)
 * Likes:    5100
 * Dislikes: 827
 * Total Accepted:    584.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * 
 * Valid operators are +, -, *, and /. Each operand may be an integer or
 * another expression.
 * 
 * Note that division between two integers should truncate toward zero.
 * 
 * It is guaranteed that the given RPN expression is always valid. That means
 * the expression would always evaluate to a result, and there will not be any
 * division by zero operation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: tokens = ["2","1","+","3","*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: tokens = ["4","13","5","/","+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
 * Output: 22
 * Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= tokens.length <= 10^4
 * tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the
 * range [-200, 200].
 * 
 * 
 */
#include <string>
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int toNum(string& str) {
        const int length = str.size();
        bool neg = false;
        int val = 0;
        int i = 0;
        if (str.at(i) == '-') {
            neg = true;
            i++;
        }
        while (i < length) {
            val = 10 * val + (str.at(i) - '0');
            i++;
        }
        if (neg) {
            return -val;
        } else {
            return val;
        }
    }
    int evalRPN(vector<string>& tokens) {
        const int size = tokens.size();
        stack<long> stk;
        for (string& curr : tokens) {
            if (curr == "+") {
                long b = stk.top();
                stk.pop();
                long a = stk.top();
                stk.pop();
                stk.push(a + b);
            } else if (curr == "-") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a - b);
            } else if (curr == "*") {
                long b = stk.top();
                stk.pop();
                long a = stk.top();
                stk.pop();
                stk.push(a * b);
            } else if (curr == "/") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a / b);
            } else {
                stk.push(toNum(curr));
            }
        }
        return stk.top();
    }
};
// @lc code=end

