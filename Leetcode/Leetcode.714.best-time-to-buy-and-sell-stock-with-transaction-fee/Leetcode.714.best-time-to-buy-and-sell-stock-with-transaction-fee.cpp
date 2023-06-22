/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 *
 * algorithms
 * Medium (63.51%)
 * Likes:    5887
 * Dislikes: 153
 * Total Accepted:    257.9K
 * Total Submissions: 387.7K
 * Testcase Example:  '[1,3,2,8,4,9]\n2'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day, and an integer fee representing a transaction fee.
 * 
 * Find the maximum profit you can achieve. You may complete as many
 * transactions as you like, but you need to pay the transaction fee for each
 * transaction.
 * 
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: prices = [1,3,2,8,4,9], fee = 2
 * Output: 8
 * Explanation: The maximum profit can be achieved by:
 * - Buying at prices[0] = 1
 * - Selling at prices[3] = 8
 * - Buying at prices[4] = 4
 * - Selling at prices[5] = 9
 * The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: prices = [1,3,7,5,10,3], fee = 3
 * Output: 6
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= prices.length <= 5 * 10^4
 * 1 <= prices[i] < 5 * 10^4
 * 0 <= fee < 5 * 10^4
 * 
 * 
 */

// @lc code=start
class Solution { // Copied from solution
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy(INT_MIN);
        int sell(0);
        for(int price : prices) {
            buy = max(buy, sell - price);
            sell = max(sell, buy + price - fee);
            // cout << buy + price - fee << '\n';
        }
        return sell;
    }
    // int maxProfit(vector<int>& prices, int fee) {
    //     const size_t size(prices.size());
    //     int* dp = new int[size + 1];
    //     dp[size] = 0;
    //     dp[size - 1] = 0;
    //     for (int i(size - 2); i >= 0; --i) {
    //         int& curr_dp(dp[i]);
    //         curr_dp = 0;
    //         int curr(prices.at(i));
    //         // cout << i << '\n';
    //         for (int j(i + 1); j < size; ++j) {
    //             curr = prices.at(j) - prices.at(i) - fee + dp[j + 1];
    //             if (curr > curr_dp) {
    //                 curr_dp = curr;
    //             }
    //             curr = dp[j];
    //             if (curr > curr_dp) {
    //                 curr_dp = curr;
    //             }
    //         }
    //     }
    //     int ans(dp[0]);
    //     delete[] dp;
    //     return ans;

    // }
};
// @lc code=end

