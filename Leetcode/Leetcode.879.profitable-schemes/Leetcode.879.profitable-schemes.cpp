/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
 *
 * https://leetcode.com/problems/profitable-schemes/description/
 *
 * algorithms
 * Hard (40.52%)
 * Likes:    725
 * Dislikes: 65
 * Total Accepted:    21.9K
 * Total Submissions: 51.1K
 * Testcase Example:  '5\n3\n[2,2]\n[2,3]'
 *
 * There is a group of n members, and a list of various crimes they could
 * commit. The i^th crime generates a profit[i] and requires group[i] members
 * to participate in it. If a member participates in one crime, that member
 * can't participate in another crime.
 * 
 * Let's call a profitable scheme any subset of these crimes that generates at
 * least minProfit profit, and the total number of members participating in
 * that subset of crimes is at most n.
 * 
 * Return the number of schemes that can be chosen. Since the answer may be
 * very large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 5, minProfit = 3, group = [2,2], profit = [2,3]
 * Output: 2
 * Explanation: To make a profit of at least 3, the group could either commit
 * crimes 0 and 1, or just crime 1.
 * In total, there are 2 schemes.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
 * Output: 7
 * Explanation: To make a profit of at least 5, the group could commit any
 * crimes, as long as they commit one.
 * There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and
 * (0,1,2).
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 100
 * 0 <= minProfit <= 100
 * 1 <= group.length <= 100
 * 1 <= group[i] <= 100
 * profit.length == group.length
 * 0 <= profit[i] <= 100
 * 
 * 
 */
#include <vector>
using namespace std;

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

// @lc code=start
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) { // Learned and then solved
        const size_t crime_size(group.size());
        const int mod(1e9+7);
        vector<vector<int>> dp(minProfit + 1, vector<int>(n + 1, 0));
        dp.at(0).at(0) = 1;
        for (size_t crime_idx(0); crime_idx < crime_size; ++crime_idx) {
            const int curr_group(group.at(crime_idx));
            const int curr_profit(profit.at(crime_idx));

            const int overflow_profit(max(minProfit - curr_profit, 0));
            // int prev_profit(minProfit); prev_profit >= overflow_profit; --prev_profit

            for (int prev_profit(minProfit); prev_profit >= 0; --prev_profit) {
                for (int prev_group(n - curr_group); prev_group >= 0; --prev_group) {
                    const int next_group(prev_group + curr_group);
                    const int next_profit(min(minProfit, prev_profit + curr_profit));
                    int& curr(dp.at(next_profit).at(next_group));
                    curr = (curr + dp.at(prev_profit).at(prev_group)) % mod;
                }
            }

            // for (int prev_profit(minProfit); prev_profit >= overflow_profit; --prev_profit) {
            //     for (int prev_group(n - curr_group); prev_group >= 0; --prev_group) {
            //         const int next_group(prev_group + curr_group);
            //         int& curr(dp.at(minProfit).at(next_group));
            //         curr = (curr + dp.at(prev_profit).at(prev_group)) % mod;
            //     }
            // }
            // for (int prev_profit(overflow_profit - 1); prev_profit >= 0; --prev_profit) {
            //     for (int prev_group(n - curr_group); prev_group >= 0; --prev_group) {
            //         const int next_group(prev_group + curr_group);
            //         const int next_profit(prev_profit + curr_profit);
            //         int& curr(dp.at(next_profit).at(next_group));
            //         curr = (curr + dp.at(prev_profit).at(prev_group)) % mod;
            //     }
            // }
        }

        int ans(0);
        for (int group_num(0); group_num <= n; ++group_num) {
            ans = (ans + dp.at(minProfit).at(group_num)) % mod;
        }
        return ans;
    }
};
// @lc code=end

