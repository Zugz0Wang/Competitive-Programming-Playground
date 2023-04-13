/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 *
 * https://leetcode.com/problems/validate-stack-sequences/description/
 *
 * algorithms
 * Medium (67.61%)
 * Likes:    4080
 * Dislikes: 71
 * Total Accepted:    201.1K
 * Total Submissions: 296.8K
 * Testcase Example:  '[1,2,3,4,5]\n[4,5,3,2,1]'
 *
 * Given two integer arrays pushed and popped each with distinct values, return
 * true if this could have been the result of a sequence of push and pop
 * operations on an initially empty stack, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
 * Output: true
 * Explanation: We might do the following sequence:
 * push(1), push(2), push(3), push(4),
 * pop() -> 4,
 * push(5),
 * pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
 * Output: false
 * Explanation: 1 cannot be popped before 2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= pushed.length <= 1000
 * 0 <= pushed[i] <= 1000
 * All the elements of pushed are unique.
 * popped.length == pushed.length
 * popped is a permutation of pushed.
 * 
 * 
 */
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) { // Independently solved
        bool* in(new bool[1001]);
        for (int i(0); i < 1001; ++i) {
            in[i] = false;
        }
        int push_idx(0);
        const int size(pushed.size());
        stack<int> s;
        for (int i : popped) {
            if (in[i]) {
                if (!s.empty() && s.top() == i) {
                    s.pop();
                } else {
                    return false;
                }
            } else {
                while (push_idx < size && pushed.at(push_idx) != i) {
                    in[pushed.at(push_idx)] = true;
                    s.push(pushed.at(push_idx));
                    ++push_idx;
                }
                if (push_idx >= size) {
                    return false;
                }
                in[pushed.at(push_idx)] = true;
                ++push_idx;
            }
        }
        return true;
    }
};
// @lc code=end

