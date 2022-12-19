/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (67.65%)
 * Likes:    8823
 * Dislikes: 202
 * Total Accepted:    505.2K
 * Total Submissions: 758.1K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the i^th day to get a warmer temperature. If there is no future
 * day for which this is possible, keep answer[i] == 0 instead.
 * 
 * 
 * Example 1:
 * Input: temperatures = [73,74,75,71,69,72,76,73]
 * Output: [1,1,4,2,1,1,0,0]
 * Example 2:
 * Input: temperatures = [30,40,50,60]
 * Output: [1,1,1,0]
 * Example 3:
 * Input: temperatures = [30,60,90]
 * Output: [1,1,0]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 * 
 * 
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int kSize = temperatures.size();
        vector<int> ans = vector<int>(kSize, 0);
        stack<int> stk;
        for (int i = 0; i < kSize; i++) {
            int curr = temperatures.at(i);
            
            while (stk.size() > 0 && temperatures.at(stk.top()) < curr) {
                ans.at(stk.top()) = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end

