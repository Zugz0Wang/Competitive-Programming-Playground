/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 *
 * https://leetcode.com/problems/boats-to-save-people/description/
 *
 * algorithms
 * Medium (52.55%)
 * Likes:    3758
 * Dislikes: 100
 * Total Accepted:    175.9K
 * Total Submissions: 330.8K
 * Testcase Example:  '[1,2]\n3'
 *
 * You are given an array people where people[i] is the weight of the i^th
 * person, and an infinite number of boats where each boat can carry a maximum
 * weight of limit. Each boat carries at most two people at the same time,
 * provided the sum of the weight of those people is at most limit.
 * 
 * Return the minimum number of boats to carry every given person.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: people = [1,2], limit = 3
 * Output: 1
 * Explanation: 1 boat (1, 2)
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: people = [3,2,2,1], limit = 3
 * Output: 3
 * Explanation: 3 boats (1, 2), (2) and (3)
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: people = [3,5,3,4], limit = 5
 * Output: 4
 * Explanation: 4 boats (3), (3), (4), (5)
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= people.length <= 5 * 10^4
 * 1 <= people[i] <= limit <= 3 * 10^4
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int numRescueBoats(vector<int>& people, const int limit) { // Original
        sort(people.begin(), people.end());
        int curr(0);
        int count(1);
        int boat_curr(0);
        const int kSize(people.size());
        int head(0);
        int tail(kSize - 1);
        while (head <= tail) {
            int head_val(people.at(head));
            int tail_val(people.at(tail));
            
            if (boat_curr < 2 && curr + tail_val <= limit) {
                curr += tail_val;
                ++boat_curr;
                tail--;
                continue;
            }
            if (boat_curr < 2 && curr + head_val <= limit) {
                curr += head_val;
                ++boat_curr;
                head++;
                continue;
            }
            ++count;
            boat_curr = 0;
            curr = 0;
        }
        return count;
    }
};
// @lc code=end

