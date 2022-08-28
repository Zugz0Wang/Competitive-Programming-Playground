/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (71.17%)
 * Likes:    14732
 * Dislikes: 556
 * Total Accepted:    1.2M
 * Total Submissions: 1.7M
 * Testcase Example:  '3'
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> dp;
    vector<string> generateParenthesis(int n) {
        dp.push_back({""});
        for (int i = 1; i <= n; i++) {
            dp.push_back({});
            for (int j = 0; j < i; j++) {
                for (string left : dp.at(j)) {
                    for (string right : dp.at(i - j - 1)) {
                        dp.at(i).push_back(left + '(' + right + ')');
                    }
                }
            }
        }
        // sort(dp.at(n).begin(), dp.at(n).end());
        return dp.at(n);
    }
};
// @lc code=end

