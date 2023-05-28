/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 *
 * https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
 *
 * algorithms
 * Hard (56.22%)
 * Likes:    2854
 * Dislikes: 53
 * Total Accepted:    56.8K
 * Total Submissions: 96.2K
 * Testcase Example:  '7\n[1,3,4,5]'
 *
 * Given a wooden stick of length n units. The stick is labelled from 0 to n.
 * For example, a stick of length 6 is labelled as follows:
 * 
 * Given an integer array cuts where cuts[i] denotes a position you should
 * perform a cut at.
 * 
 * You should perform the cuts in order, you can change the order of the cuts
 * as you wish.
 * 
 * The cost of one cut is the length of the stick to be cut, the total cost is
 * the sum of costs of all cuts. When you cut a stick, it will be split into
 * two smaller sticks (i.e. the sum of their lengths is the length of the stick
 * before the cut). Please refer to the first example for a better
 * explanation.
 * 
 * Return the minimum total cost of the cuts.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 7, cuts = [1,3,4,5]
 * Output: 16
 * Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the
 * following scenario:
 * 
 * The first cut is done to a rod of length 7 so the cost is 7. The second cut
 * is done to a rod of length 6 (i.e. the second part of the first cut), the
 * third is done to a rod of length 4 and the last cut is to a rod of length 3.
 * The total cost is 7 + 6 + 4 + 3 = 20.
 * Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario
 * with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
 * 
 * Example 2:
 * 
 * 
 * Input: n = 9, cuts = [5,6,1,4,2]
 * Output: 22
 * Explanation: If you try the given cuts ordering the cost will be 25.
 * There are much ordering with total cost <= 25, for example, the order [4, 6,
 * 5, 2, 1] has total cost = 22 which is the minimum possible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 10^6
 * 1 <= cuts.length <= min(n - 1, 100)
 * 1 <= cuts[i] <= n - 1
 * All the integers in cuts array are distinct.
 * 
 * 
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution { // Independently solved (hinted by tags of dynamic programming and sorting)
public:

    int dp[101][101];
    int n;
    vector<int> cuts;
    int calculateCut(size_t begin, size_t end) {
        int& curr_dp(dp[begin][end]);
        if (begin >= end) {
            return 0;
        } 
        // else if (begin + 1 == end) {
        //     int prev_cut(0);
        //     int next_cut(n);
        //     int curr_cut(cuts.at(begin));
        //     if (begin > 0) {
        //         prev_cut = cuts.at(begin - 1);
        //     }
        //     if (begin < cuts.size() - 1) {
        //         next_cut = cuts.at(begin + 1);
        //     }
        //     curr_dp = next_cut - prev_cut;
        // }
        int lower(0);
        int upper(n);
        if (begin > 0) {
            lower = cuts.at(begin - 1);
        }
        if (end < cuts.size()) {
            upper = cuts.at(end);
        }
        int curr_cut_cost(upper - lower);

        int min_cost(-1);
        for (size_t i(begin); i < end; ++i) {
            int curr_cost(dp[begin][i] + dp[i + 1][end]);
            if (curr_cost < min_cost || min_cost == -1) {
                min_cost = curr_cost;
            }
        }
        curr_dp = curr_cut_cost + min_cost;
        // cout << begin << ' ' << end << ' ' << curr_dp << '\n';
        return curr_dp;
    }

    int minCost(int n_, vector<int>& cuts_) {
        n = n_;
        cuts = cuts_;
        sort(cuts.begin(), cuts.end());
        size_t cuts_size(cuts.size());
        for (size_t i(0); i < cuts_size; ++i) {
            dp[i][i] = 0;
        }

        for (size_t len(1); len < cuts_size; ++len) {
            size_t end(cuts_size - len);
            for (size_t start(0); start <= end; ++start) {
                calculateCut(start, start + len);
            }
        }
        return calculateCut(0, cuts_size);
    }
};
// @lc code=end

