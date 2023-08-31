/*
 * @lc app=leetcode id=1326 lang=cpp
 *
 * [1326] Minimum Number of Taps to Open to Water a Garden
 *
 * https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/
 *
 * algorithms
 * Hard (47.78%)
 * Likes:    2113
 * Dislikes: 124
 * Total Accepted:    73.4K
 * Total Submissions: 154.3K
 * Testcase Example:  '5\n[3,4,1,1,0,0]'
 *
 * There is a one-dimensional garden on the x-axis. The garden starts at the
 * point 0 and ends at the point n. (i.e The length of the garden is n).
 * 
 * There are n + 1 taps located at points [0, 1, ..., n] in the garden.
 * 
 * Given an integer n and an integer array ranges of length n + 1 where
 * ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i],
 * i + ranges[i]] if it was open.
 * 
 * Return the minimum number of taps that should be open to water the whole
 * garden, If the garden cannot be watered return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 5, ranges = [3,4,1,1,0,0]
 * Output: 1
 * Explanation: The tap at point 0 can cover the interval [-3,3]
 * The tap at point 1 can cover the interval [-3,5]
 * The tap at point 2 can cover the interval [1,3]
 * The tap at point 3 can cover the interval [2,4]
 * The tap at point 4 can cover the interval [4,4]
 * The tap at point 5 can cover the interval [5,5]
 * Opening Only the second tap will water the whole garden [0,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3, ranges = [0,0,0,0]
 * Output: -1
 * Explanation: Even if you activate all the four taps you cannot water the
 * whole garden.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * ranges.length == n + 1
 * 0 <= ranges[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution { // Learned from solution
public:
    int minTaps(int n, vector<int>& ranges) {
        const int size(ranges.size());
        vector<int> dp_v(size + 1, size + 1);
        int* dp(dp_v.data());
        dp[0] = 0;
        for (int i(0); i < size; ++i) {
            int start(0);
            int curr(ranges.at(i));
            if (i - curr > 0) {
                start = i - curr;
            }
            int end(n);
            if (i + curr < end) {
                end = i + curr;
            }
            int prev_dp(dp[start] + 1);
            for (int j(start + 1); j <= end; ++j) {
                if (dp[j] > prev_dp) {
                    dp[j] = prev_dp;
                }
            }
        }
        if (dp[n] > size) {
            return -1;
        }
        return dp[n];
    }
};
// @lc code=end

