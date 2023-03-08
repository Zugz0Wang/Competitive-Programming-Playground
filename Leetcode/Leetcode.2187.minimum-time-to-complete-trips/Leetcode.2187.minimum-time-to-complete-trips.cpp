/*
 * @lc app=leetcode id=2187 lang=cpp
 *
 * [2187] Minimum Time to Complete Trips
 *
 * https://leetcode.com/problems/minimum-time-to-complete-trips/description/
 *
 * algorithms
 * Medium (31.15%)
 * Likes:    2246
 * Dislikes: 137
 * Total Accepted:    87.6K
 * Total Submissions: 222.9K
 * Testcase Example:  '[1,2,3]\n5'
 *
 * You are given an array time where time[i] denotes the time taken by the i^th
 * bus to complete one trip.
 * 
 * Each bus can make multiple trips successively; that is, the next trip can
 * start immediately after completing the current trip. Also, each bus operates
 * independently; that is, the trips of one bus do not influence the trips of
 * any other bus.
 * 
 * You are also given an integer totalTrips, which denotes the number of trips
 * all buses should make in total. Return the minimum time required for all
 * buses to complete at least totalTrips trips.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: time = [1,2,3], totalTrips = 5
 * Output: 3
 * Explanation:
 * - At time t = 1, the number of trips completed by each bus are [1,0,0]. 
 * ⁠ The total number of trips completed is 1 + 0 + 0 = 1.
 * - At time t = 2, the number of trips completed by each bus are [2,1,0]. 
 * ⁠ The total number of trips completed is 2 + 1 + 0 = 3.
 * - At time t = 3, the number of trips completed by each bus are [3,1,1]. 
 * ⁠ The total number of trips completed is 3 + 1 + 1 = 5.
 * So the minimum time needed for all buses to complete at least 5 trips is
 * 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: time = [2], totalTrips = 1
 * Output: 2
 * Explanation:
 * There is only one bus, and it will complete its first trip at t = 2.
 * So the minimum time needed to complete 1 trip is 2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= time.length <= 10^5
 * 1 <= time[i], totalTrips <= 10^7
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public: // Learned from solution
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        const int kSize = time.size();
        long long head(1);
        long long max_time = time.at(kSize - 1);
        long long tail(totalTrips * max_time + 1);
        while (head < tail) {
            long long mid_time((head + tail) / 2);
            // cout << head << ' ' << tail << '\n';
            long long curr_total(0);
            for (int t : time) {
                curr_total += mid_time / t;
            }

            if (curr_total < totalTrips) {
                head = mid_time + 1;
            } else {
                tail = mid_time;
            }
        }
        return head;
    }
};
// @lc code=end

