// @lc app=leetcode id=20 lang=cpp
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        const int kLength = s.length();
        for(int i = 0; i < kLength; i++) {
            char curr_char = s[i];
            if (curr_char == '(' || curr_char == '[' || curr_char == '{') {
                stk.push(curr_char);
            } else {
                if (stk.size() == 0) {
                    return false; // if the stack is empty, not match
                }
                char prev_char = stk.top();
                if (prev_char == '(' && curr_char != ')') { // if the previous bracket doesn't match
                    return false;
                } else if (prev_char == '[' && curr_char != ']') {
                    return false;
                } else if (prev_char == '{' && curr_char != '}') {
                    return false;
                }
                stk.pop();
            }
        }
        if (stk.size() == 0) {
            return true;
        } else {
            return false;
        }
        
    }
};
// @lc code=end