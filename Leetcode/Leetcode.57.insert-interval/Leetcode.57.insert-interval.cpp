/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Medium (37.73%)
 * Likes:    6802
 * Dislikes: 479
 * Total Accepted:    666.4K
 * Total Submissions: 1.7M
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * You are given an array of non-overlapping intervals intervals where
 * intervals[i] = [starti, endi] represent the start and the end of the i^th
 * interval and intervals is sorted in ascending order by starti. You are also
 * given an interval newInterval = [start, end] that represents the start and
 * end of another interval.
 * 
 * Insert newInterval into intervals such that intervals is still sorted in
 * ascending order by starti and intervals still does not have any overlapping
 * intervals (merge overlapping intervals if necessary).
 * 
 * Return intervals after the insertion.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^5
 * intervals is sorted by starti in ascending order.
 * newInterval.length == 2
 * 0 <= start <= end <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int search(vector<vector<int>>& intervals, int val) {
        int head = 0;
        int tail = intervals.size();
        int idx = -1;
        while (head < tail) {
            int mid_idx = (head + tail) / 2;
            int mid_val0 = intervals.at(mid_idx).at(0);
            int mid_val1 = intervals.at(mid_idx).at(1);
            if (val >= mid_val0 && val <= mid_val1) {
                return mid_idx;
            } else if (val < mid_val0) {
                tail = mid_idx;
            } else {
                head = mid_idx + 1;
            }
        }
        if (tail == 0) {
            return -1;
        } else {
            return tail;
        }
    } 
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        const int kSize = intervals.size();
        int val0 = newInterval.at(0);
        int val1 = newInterval.at(1);
        // int idx0 = search(intervals, val0);
        // int idx1 = search(intervals, val1);
        // cout << idx0 << ' ' << idx1;
        int new_val0 = val0;
        // if (idx0 >= 0 && idx0 < kSize) {
        //     new_val0 = intervals.at(idx0).at(0);
        // }

        int new_val1 = val1;
        // if (idx1 >= 0 && idx1 < kSize) {
        //     new_val1 = intervals.at(idx1).at(1);
        // }
        vector<vector<int>> ans;
        int i = 0;
        while (i < kSize && val0 > intervals.at(i).at(1) ) {
            ans.push_back(intervals.at(i));
            i++;
        }

        if (i < kSize && val0 >= intervals.at(i).at(0)) {
            new_val0 = intervals.at(i).at(0);
        }
        
        while (i < kSize && val1 > intervals.at(i).at(1)) {
            i++;
        }

        if (i < kSize && val1 >= intervals.at(i).at(0)) {
            new_val1 = intervals.at(i).at(1);
            i++;
        }

        ans.push_back({new_val0, new_val1});

        while (i < kSize) {
            ans.push_back(intervals.at(i));
            i++;
        }
        
        return ans;
    }
    // [[1,2],[3,5],[6,7],[8,10],[12,16]]\n[4,8]
    // [[4,5], [8,9]]\n[1,2]
};
// @lc code=end

