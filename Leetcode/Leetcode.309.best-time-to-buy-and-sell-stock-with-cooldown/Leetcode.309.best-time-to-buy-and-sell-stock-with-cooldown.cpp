/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (53.68%)
 * Likes:    7044
 * Dislikes: 239
 * Total Accepted:    342.1K
 * Total Submissions: 624.7K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 * 
 * Find the maximum profit you can achieve. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * After you sell your stock, you cannot buy stock on the next day (i.e.,
 * cooldown one day).
 * 
 * 
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: prices = [1,2,3,0,2]
 * Output: 3
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: prices = [1]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= prices.length <= 5000
 * 0 <= prices[i] <= 1000
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int kSize = prices.size();
        if (kSize == 0) {
            return 0;
        }
        int h1_skip = -prices.at(0);
        int h1_sell = 0;
        int h0_skip = 0;
        int h0_buy = h1_skip;
        for (int i = 1; i < kSize; i++) {
            if (h1_skip > h0_buy) {
                h1_skip = h1_skip;
            } else {
                h1_skip = h0_buy;
            }
            h0_buy = h0_skip - prices.at(i);
            if (h0_skip > h1_sell) {
                h0_skip = h0_skip;
            } else {
                h0_skip = h1_sell;
            }
            h1_sell = h1_skip + prices.at(i);
        }
        if (h1_sell > h0_skip) {
            return h1_sell;
        } else {
            return h0_skip;
        }
    }
};
// @lc code=end

