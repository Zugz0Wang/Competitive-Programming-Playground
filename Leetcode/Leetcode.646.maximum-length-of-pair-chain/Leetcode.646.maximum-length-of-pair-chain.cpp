/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 *
 * https://leetcode.com/problems/maximum-length-of-pair-chain/description/
 *
 * algorithms
 * Medium (56.15%)
 * Likes:    3198
 * Dislikes: 116
 * Total Accepted:    147.1K
 * Total Submissions: 258.2K
 * Testcase Example:  '[[1,2],[2,3],[3,4]]'
 *
 * You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and
 * lefti < righti.
 * 
 * A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can
 * be formed in this fashion.
 * 
 * Return the length longest chain which can be formed.
 * 
 * You do not need to use up all the given intervals. You can select pairs in
 * any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: pairs = [[1,2],[2,3],[3,4]]
 * Output: 2
 * Explanation: The longest chain is [1,2] -> [3,4].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: pairs = [[1,2],[7,8],[4,5]]
 * Output: 3
 * Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == pairs.length
 * 1 <= n <= 1000
 * -1000 <= lefti < righti <= 1000
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        size_t N(pairs.size());
        sort(pairs.begin(), pairs.end());
        vector<int> dp(N, 1);
        for (size_t i(1); i < N; ++i) {
            const vector<int>& curr(pairs.at(i));
            for (size_t j(i - 1); j < N; --j) {
                const vector<int>& prev(pairs.at(j));
                if (prev.at(1) < curr.at(0) && dp.at(j) + 1 > dp.at(i)) {
                    dp.at(i) = dp.at(j) + 1;
                }
            }
        }
        int ans(1);
        for (size_t i(0); i < N; ++i) {
            if (dp.at(i) > ans) {
                ans = dp.at(i);
            }
        }
        return ans;
    }
};
// @lc code=end

