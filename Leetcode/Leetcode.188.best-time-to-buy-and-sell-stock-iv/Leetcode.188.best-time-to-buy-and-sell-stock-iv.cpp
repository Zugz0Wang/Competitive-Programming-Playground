/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (34.96%)
 * Likes:    4672
 * Dislikes: 165
 * Total Accepted:    277.4K
 * Total Submissions: 783.6K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * You are given an integer array prices where prices[i] is the price of a
 * given stock on the i^th day, and an integer k.
 * 
 * Find the maximum profit you can achieve. You may complete at most k
 * transactions.
 * 
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 2, prices = [2,4,1]
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 2, prices = [3,2,6,5,0,3]
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3),
 * profit = 3-0 = 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= k <= 100
 * 0 <= prices.length <= 1000
 * 0 <= prices[i] <= 1000
 * 
 * 
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int curr[1002][2];
    int next[1002][2];
    int maxProfit(int k, vector<int>& prices) {
        memset(curr, 0, sizeof(curr));
        memset(next, 0, sizeof(next));
        const int kSize = prices.size();
        // cout << kSize;
        for (int idx = kSize - 1; idx >= 0; idx--) {
            const int kPrice = prices.at(idx);
            for (int count = 0; count < k; count++) { // Whether buy new stock
                curr[count][0] = max(next[count][1] - kPrice, next[count][0]);
            }
            for (int count = 0; count < k; count++) { // Whether buy new stock
                curr[count][1] = max(next[count + 1][0] + kPrice, next[count][1]);
            }
            for (int i = 0; i < kSize; i++) {
                next[i][0] = curr[i][0];
                next[i][1] = curr[i][1];
            }
        }
        return curr[0][0];
    }
};
// @lc code=end

