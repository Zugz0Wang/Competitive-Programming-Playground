/*
 * @lc app=leetcode id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
 *
 * https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/
 *
 * algorithms
 * Hard (55.93%)
 * Likes:    2242
 * Dislikes: 216
 * Total Accepted:    108.5K
 * Total Submissions: 185.1K
 * Testcase Example:  '[6,5,4,3,2,1]\n2'
 *
 * You want to schedule a list of jobs in d days. Jobs are dependent (i.e To
 * work on the i^th job, you have to finish all the jobs j where 0 <= j < i).
 * 
 * You have to finish at least one task every day. The difficulty of a job
 * schedule is the sum of difficulties of each day of the d days. The
 * difficulty of a day is the maximum difficulty of a job done on that day.
 * 
 * You are given an integer array jobDifficulty and an integer d. The
 * difficulty of the i^th job is jobDifficulty[i].
 * 
 * Return the minimum difficulty of a job schedule. If you cannot find a
 * schedule for the jobs return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: jobDifficulty = [6,5,4,3,2,1], d = 2
 * Output: 7
 * Explanation: First day you can finish the first 5 jobs, total difficulty =
 * 6.
 * Second day you can finish the last job, total difficulty = 1.
 * The difficulty of the schedule = 6 + 1 = 7 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: jobDifficulty = [9,9,9], d = 4
 * Output: -1
 * Explanation: If you finish a job per day you will still have a free day. you
 * cannot find a schedule for the given jobs.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: jobDifficulty = [1,1,1], d = 3
 * Output: 3
 * Explanation: The schedule is one job per day. total difficulty will be
 * 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= jobDifficulty.length <= 300
 * 0 <= jobDifficulty[i] <= 1000
 * 1 <= d <= 10
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    const int INF = 1e9;
    int dp[305] = {INF};
    int minDifficulty(vector<int>& jobDifficulty, int D) {
        const int kSize = jobDifficulty.size();
        if (kSize < D) {
            return -1;
        }
        dp[kSize] = 0;
        for (int i = kSize - 1; i >= 0; --i)
            dp[i] = max(dp[i + 1], jobDifficulty[i]);
        for (int day = 1; day <= D; day++) {
            for (int i = 0; i <= kSize - day; i++) {
                int max_val = 0; dp[i] = INF; // ??
                for (int j = i; j <= kSize - day ; j++) {
                    int today_diff = jobDifficulty.at(j);
                    if (today_diff > max_val) {
                        max_val = today_diff;
                    }
                    if (max_val + dp[j + 1] < dp[i]) {
                        dp[i] = max_val + dp[j + 1];
                    }
                }
            }
        }
        // Original:
        // for (int d = 1; d <= D; ++d) {
        //     for (int i = 0; i <= kSize - d; ++i) {
        //         int maxd = 0; dp[i] = INF;
        //         for (int j = i; j <= kSize - d; ++j) {
        //             maxd = max(maxd, jobDifficulty[j]);
        //             dp[i] = min(dp[i], maxd + dp[j + 1]);
        //         }
        //     }
        // }
        return dp[0];
    }
};
// @lc code=end

