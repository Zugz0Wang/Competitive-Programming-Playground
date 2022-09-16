/*
 * @lc app=leetcode id=1383 lang=cpp
 *
 * [1383] Maximum Performance of a Team
 *
 * https://leetcode.com/problems/maximum-performance-of-a-team/description/
 *
 * algorithms
 * Hard (41.64%)
 * Likes:    1268
 * Dislikes: 41
 * Total Accepted:    41.1K
 * Total Submissions: 98.5K
 * Testcase Example:  '6\n[2,10,3,1,5,8]\n[5,4,3,9,7,2]\n2'
 *
 * You are given two integers n and k and two integer arrays speed and
 * efficiency both of length n. There are n engineers numbered from 1 to n.
 * speed[i] and efficiency[i] represent the speed and efficiency of the i^th
 * engineer respectively.
 * 
 * Choose at most k different engineers out of the n engineers to form a team
 * with the maximum performance.
 * 
 * The performance of a team is the sum of their engineers' speeds multiplied
 * by the minimum efficiency among their engineers.
 * 
 * Return the maximum performance of this team. Since the answer can be a huge
 * number, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
 * Output: 60
 * Explanation: 
 * We have the maximum performance of the team by selecting engineer 2 (with
 * speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7).
 * That is, performance = (10 + 5) * min(4, 7) = 60.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
 * Output: 68
 * Explanation:
 * This is the same example as the first but k = 3. We can select engineer 1,
 * engineer 2 and engineer 5 to get the maximum performance of the team. That
 * is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
 * Output: 72
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= n <= 10^5
 * speed.length == n
 * efficiency.length == n
 * 1 <= speed[i] <= 10^5
 * 1 <= efficiency[i] <= 10^8
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> e_arr(n);
        for (int i = 0; i < n; i++) {
            e_arr.at(i).first = efficiency.at(i);
            e_arr.at(i).second = speed.at(i);
        }
        sort(rbegin(e_arr), rend(e_arr));
        long sum = 0;
        long to_return = 0;
        int prev_e = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            int curr_e = e_arr.at(i).first;
            int curr_s = e_arr.at(i).second;
            pq.emplace(curr_s);
            // sum += curr_s;
            if (pq.size() > k) {
                int pop_s = pq.top();
                pq.pop();
                if (pop_s != curr_s) {
                    sum += curr_s - pop_s;
                } else {
                    curr_e = prev_e;
                }
            } else {
                sum += curr_s;
            }
            long curr_p = sum * curr_e;
            if (curr_p > to_return) {
                to_return = curr_p;
            }
            prev_e = curr_e;
        }

        return  to_return % (int)(1e9 + 7);
        
    }
};
// @lc code=end

