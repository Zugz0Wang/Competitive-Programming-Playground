/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 *
 * https://leetcode.com/problems/sum-of-subarray-minimums/description/
 *
 * algorithms
 * Medium (34.18%)
 * Likes:    5208
 * Dislikes: 350
 * Total Accepted:    120.7K
 * Total Submissions: 343.6K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array of integers arr, find the sum of min(b), where b ranges over
 * every (contiguous) subarray of arr. Since the answer may be large, return
 * the answer modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [3,1,2,4]
 * Output: 17
 * Explanation: 
 * Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4],
 * [3,1,2,4]. 
 * Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
 * Sum is 17.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [11,81,94,43,3]
 * Output: 444
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 3 * 10^4
 * 1 <= arr[i] <= 3 * 10^4
 * 
 * 
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int dp[30010];
    const int kMod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        const int kSize = arr.size();
        memset(dp, 0, sizeof(dp));
        stack<int> stk;
        for (int i = 0; i < kSize; i++) {
            int curr_val = arr.at(i);
            while (!stk.empty() && arr.at(stk.top()) >= curr_val) {
                stk.pop();
            }
            if (!stk.empty()) {
                int prev_idx = stk.top();
                dp[i] = dp[prev_idx] + ((i - prev_idx) * curr_val) % kMod;
            } else {
                dp[i] = ((i + 1) * curr_val) % kMod;
            }
            stk.push(i);
        }
        int ans = 0;
        for (int i = 0; i < kSize; i++) {
            ans = (ans + dp[i]) % kMod;
        }
        return ans;
    }
};
// @lc code=end

