/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 *
 * https://leetcode.com/problems/numbers-with-same-consecutive-differences/description/
 *
 * algorithms
 * Medium (47.84%)
 * Likes:    2291
 * Dislikes: 176
 * Total Accepted:    100.5K
 * Total Submissions: 178.8K
 * Testcase Example:  '3\n7'
 *
 * Return all non-negative integers of length n such that the absolute
 * difference between every two consecutive digits is k.
 * 
 * Note that every number in the answer must not have leading zeros. For
 * example, 01 has one leading zero and is invalid.
 * 
 * You may return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 7
 * Output: [181,292,707,818,929]
 * Explanation: Note that 070 is not a valid number, because it has leading
 * zeroes.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2, k = 1
 * Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 9
 * 0 <= k <= 9
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> to_return;
    long path = 0;
    int length = 1;
    void helper(int n, int k, int curr) {
        if (length == n) {
            path = path * 10 + curr;
            to_return.push_back(path);
            path /= 10;
            return;
        }
        int next1 = curr + k;
        int next2 = curr - k;
        if (next2 >= 0) {
            length++;
            path = path * 10 + curr;
            helper(n, k, next2);
            path /= 10;
            length--;
        }
        if (next1 < 10 && next1 != next2) {
            path = path * 10 + curr;
            length++;
            helper(n, k, next1);
            length--;
            path /= 10;
        }
        
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i < 10; i++) {
            helper(n, k, i);
        }
        return to_return;
    }
};
// @lc code=end

