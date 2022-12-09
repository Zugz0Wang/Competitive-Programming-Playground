/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 *
 * https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
 *
 * algorithms
 * Hard (50.93%)
 * Likes:    4662
 * Dislikes: 55
 * Total Accepted:    167.7K
 * Total Submissions: 313.9K
 * Testcase Example:  '[1,2,3,3]\n[3,4,5,6]\n[50,10,40,70]'
 *
 * We have n jobs, where every job is scheduled to be done from startTime[i] to
 * endTime[i], obtaining a profit of profit[i].
 * 
 * You're given the startTime, endTime and profit arrays, return the maximum
 * profit you can take such that there are no two jobs in the subset with
 * overlapping time range.
 * 
 * If you choose a job that ends at time X you will be able to start another
 * job that starts at time X.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
 * Output: 120
 * Explanation: The subset chosen is the first and fourth job. 
 * Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
 * 
 * 
 * Example 2:
 * 
 * ⁠
 * 
 * 
 * Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit =
 * [20,20,100,70,60]
 * Output: 150
 * Explanation: The subset chosen is the first, fourth and fifth job. 
 * Profit obtained 150 = 20 + 70 + 60.
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
 * Output: 6
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
 * 1 <= startTime[i] < endTime[i] <= 10^9
 * 1 <= profit[i] <= 10^4
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    struct job {
        int start;
        int end;
        int pro;
        job(int s, int e, int p): start(s), end(e), pro(p) {}
        bool operator<(const job b) {
            if (end == b.end && start == b.start) {
                return pro < b.pro;
            } else if (end == b.end) {
                return start < b.start;
            } else {
                return end < b.end;
            }
        }
    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int kSize = startTime.size();
        vector<job> jobs;
        for (int i = 0; i < kSize; i++) {
            jobs.push_back(job(startTime.at(i), endTime.at(i), profit.at(i)));
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp = {{0, 0}};
        for (auto& job: jobs) {
            int cur = prev(dp.upper_bound(job.start))->second + job.pro;
            if (cur > dp.rbegin()->second) {
                dp[job.end] = cur;
            }
        }
        return dp.rbegin() -> second;
    }
};
// @lc code=end

