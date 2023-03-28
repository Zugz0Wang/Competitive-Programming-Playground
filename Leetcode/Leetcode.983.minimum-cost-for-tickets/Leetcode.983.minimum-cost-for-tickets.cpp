/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 *
 * https://leetcode.com/problems/minimum-cost-for-tickets/description/
 *
 * algorithms
 * Medium (64.29%)
 * Likes:    5686
 * Dislikes: 95
 * Total Accepted:    190.7K
 * Total Submissions: 296.1K
 * Testcase Example:  '[1,4,6,7,8,20]\n[2,7,15]'
 *
 * You have planned some train traveling one year in advance. The days of the
 * year in which you will travel are given as an integer array days. Each day
 * is an integer from 1 to 365.
 * 
 * Train tickets are sold in three different ways:
 * 
 * 
 * a 1-day pass is sold for costs[0] dollars,
 * a 7-day pass is sold for costs[1] dollars, and
 * a 30-day pass is sold for costs[2] dollars.
 * 
 * 
 * The passes allow that many days of consecutive travel.
 * 
 * 
 * For example, if we get a 7-day pass on day 2, then we can travel for 7 days:
 * 2, 3, 4, 5, 6, 7, and 8.
 * 
 * 
 * Return the minimum number of dollars you need to travel every day in the
 * given list of days.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: days = [1,4,6,7,8,20], costs = [2,7,15]
 * Output: 11
 * Explanation: For example, here is one way to buy passes that lets you travel
 * your travel plan:
 * On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
 * On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3,
 * 4, ..., 9.
 * On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
 * In total, you spent $11 and covered all the days of your travel.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
 * Output: 17
 * Explanation: For example, here is one way to buy passes that lets you travel
 * your travel plan:
 * On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1,
 * 2, ..., 30.
 * On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
 * In total, you spent $17 and covered all the days of your travel.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= days.length <= 365
 * 1 <= days[i] <= 365
 * days is in strictly increasing order.
 * costs.length == 3
 * 1 <= costs[i] <= 1000
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    
    int mincostTickets(vector<int>& days, vector<int>& costs) { // Learned
        const int kSize = days.size();
        vector<int> dp(366, 0);
    
        int pass1 = costs.at(0);
        int pass2 = costs.at(1);
        int pass7 = costs.at(2);

        // if (pass2 > pass7) {
        //     pass2 = pass7;
        // }

        // if (pass1 > pass2) {
        //     pass1 = pass2;
        // }

        for (int i = 0; i < kSize; ++i) {
            int day = days.at(i);
            int& curr = dp.at(day);
            curr = dp.at(day - 1) + pass1;
            if (day > 6 ) {
                if (curr > dp.at(day - 7) + pass2) {
                    curr = dp.at(day - 7) + pass2;
                }
            } else {
                if (curr > dp.at(0) + pass2) {
                    curr = dp.at(0) + pass2;
                }
            }
            if (day > 29 ) {
                if (curr > dp.at(day - 30) + pass7) {
                    curr = dp.at(day - 30) + pass7;
                }
            } else {
                if (curr > dp.at(0) + pass7) {
                    curr = dp.at(0) + pass7;
                }
            }
            if (i + 1 < kSize) {
                for (int j = day + 1; j < days.at(i + 1); ++j) {
                    dp.at(j) = curr;
                }
            }
            // cout << curr << ' ';
            
        }
        return dp.at(days.at(kSize - 1));
    }
};
// @lc code=end

