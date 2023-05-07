/*
 * @lc app=leetcode id=1964 lang=cpp
 *
 * [1964] Find the Longest Valid Obstacle Course at Each Position
 *
 * https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/description/
 *
 * algorithms
 * Hard (46.30%)
 * Likes:    502
 * Dislikes: 13
 * Total Accepted:    11.6K
 * Total Submissions: 23.8K
 * Testcase Example:  '[1,2,3,2]'
 *
 * You want to build some obstacle courses. You are given a 0-indexed integer
 * array obstacles of length n, where obstacles[i] describes the height of the
 * i^th obstacle.
 * 
 * For every index i between 0 and n - 1 (inclusive), find the length of the
 * longest obstacle course in obstacles such that:
 * 
 * 
 * You choose any number of obstacles between 0 and i inclusive.
 * You must include the i^th obstacle in the course.
 * You must put the chosen obstacles in the same order as they appear in
 * obstacles.
 * Every obstacle (except the first) is taller than or the same height as the
 * obstacle immediately before it.
 * 
 * 
 * Return an array ans of length n, where ans[i] is the length of the longest
 * obstacle course for index i as described above.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: obstacles = [1,2,3,2]
 * Output: [1,2,3,3]
 * Explanation: The longest valid obstacle course at each position is:
 * - i = 0: [1], [1] has length 1.
 * - i = 1: [1,2], [1,2] has length 2.
 * - i = 2: [1,2,3], [1,2,3] has length 3.
 * - i = 3: [1,2,3,2], [1,2,2] has length 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: obstacles = [2,2,1]
 * Output: [1,2,1]
 * Explanation: The longest valid obstacle course at each position is:
 * - i = 0: [2], [2] has length 1.
 * - i = 1: [2,2], [2,2] has length 2.
 * - i = 2: [2,2,1], [1] has length 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: obstacles = [3,1,5,6,4,2]
 * Output: [1,1,2,3,2,2]
 * Explanation: The longest valid obstacle course at each position is:
 * - i = 0: [3], [3] has length 1.
 * - i = 1: [3,1], [1] has length 1.
 * - i = 2: [3,1,5], [3,5] has length 2. [1,5] is also valid.
 * - i = 3: [3,1,5,6], [3,5,6] has length 3. [1,5,6] is also valid.
 * - i = 4: [3,1,5,6,4], [3,4] has length 2. [1,4] is also valid.
 * - i = 5: [3,1,5,6,4,2], [1,2] has length 2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == obstacles.length
 * 1 <= n <= 10^5
 * 1 <= obstacles[i] <= 10^7
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution { // Learned from solution
public:
    size_t binaryInsert(vector<int>& seq, int insert) {
        size_t begin(0);
        size_t end(seq.size());
        while (begin < end) {
            size_t mid_idx((begin + end) / 2);
            int mid_val(seq.at(mid_idx));
            if (mid_val > insert) {
                end = mid_idx;
            } else {
                begin = mid_idx + 1;
            }
        }
        return begin;
    }

    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> seq;
        const size_t size(obstacles.size());
        vector<int> ans(size, 0);
        for (size_t i(0); i < size; ++i) {
            int insert(obstacles.at(i));
            size_t insert_idx(binaryInsert(seq, insert));
            if (insert_idx >= seq.size()) {
                seq.push_back(0);
            }
            seq.at(insert_idx) = insert;
            ans.at(i) = insert_idx + 1;
        }        
        return ans;
    }
};
// @lc code=end

