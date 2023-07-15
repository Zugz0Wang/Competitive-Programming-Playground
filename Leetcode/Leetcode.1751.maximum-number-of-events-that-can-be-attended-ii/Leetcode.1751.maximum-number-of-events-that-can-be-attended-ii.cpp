/*
 * @lc app=leetcode id=1751 lang=cpp
 *
 * [1751] Maximum Number of Events That Can Be Attended II
 *
 * https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/
 *
 * algorithms
 * Hard (55.45%)
 * Likes:    1310
 * Dislikes: 23
 * Total Accepted:    39.7K
 * Total Submissions: 65.5K
 * Testcase Example:  '[[1,2,4],[3,4,3],[2,3,1]]\n2'
 *
 * You are given an array of events where events[i] = [startDayi, endDayi,
 * valuei]. The i^th event starts at startDayi and ends at endDayi, and if you
 * attend this event, you will receive a value of valuei. You are also given an
 * integer k which represents the maximum number of events you can attend.
 * 
 * You can only attend one event at a time. If you choose to attend an event,
 * you must attend the entire event. Note that the end day is inclusive: that
 * is, you cannot attend two events where one of them starts and the other ends
 * on the same day.
 * 
 * Return the maximum sum of values that you can receive by attending
 * events.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
 * Output: 7
 * Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value
 * of 4 + 3 = 7.
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
 * Output: 10
 * Explanation: Choose event 2 for a total value of 10.
 * Notice that you cannot attend any other event as they overlap, and that you
 * do not have to attend k events.
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
 * Output: 9
 * Explanation: Although the events do not overlap, you can only attend 3
 * events. Pick the highest valued three.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= events.length
 * 1 <= k * events.length <= 10^6
 * 1 <= startDayi <= endDayi <= 10^9
 * 1 <= valuei <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution { // Learned from solution (busy)
public:

    vector<vector<int>> events;
    int* dp;
    int size;

    int findNextIdx(int start, int begin) {
        int end(size);
        while (begin < end) {
            int mid_idx((begin + end) / 2);
            int mid_start(events.at(mid_idx).at(0));
            if (mid_start < start) {
                begin = mid_idx + 1;
            } else {
                end = mid_idx;
            }
        }
        return begin;
    }

    int solve(int i, int k) {
        if (i < 0 || i >= size) {
            return 0;
        }
        if (k <= 0) {
            return 0;
        }
        int& curr_dp(dp[k * size + i]);
        if (curr_dp > -1) {
            return curr_dp;
        }
        const vector<int>& curr_event(events.at(i));
        int not_attend_dp(solve(i + 1, k));
        int attend_dp(curr_event.at(2) + solve(findNextIdx(curr_event.at(1) + 1, i + 1), k - 1));

        if (attend_dp > not_attend_dp) {
            curr_dp = attend_dp;
        } else {
            curr_dp = not_attend_dp;
        }
        return curr_dp;
    }

    int maxValue(vector<vector<int>>& events_, int k) {
        events = events_;
        size = events.size();
        sort(events.begin(), events.end());

        dp = new int[(k + 1) * size];
        
        for (int i(0); i < (k + 1) * size; ++i) {
            dp[i] = -1;
        }

        int ans(solve(0, k));
        delete[] dp;
        return ans;
    }
};
// @lc code=end

