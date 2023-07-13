/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (45.22%)
 * Likes:    14155
 * Dislikes: 562
 * Total Accepted:    1.2M
 * Total Submissions: 2.7M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i]
 * = [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 * 
 * 
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 * 
 * 
 * Return true if you can finish all courses. Otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should also have finished course 1. So it is impossible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs prerequisites[i] are unique.
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<forward_list<int>> g(numCourses);
        vector<int> degrees(numCourses, 0);
        for (const vector<int>& pre : prerequisites) {
            int a(pre.at(0));
            int b(pre.at(1));

            g.at(b).push_front(a);
            degrees.at(a) += 1;
        }
        
        queue<int> q;
        int finished(0);
        for (int i(0); i < numCourses; ++i) {
            if (degrees.at(i) == 0) {
                q.push(i);
                
            }
        }
        
        while (!q.empty()) {
            int curr(q.front());
            finished += 1;
            q.pop();
            const forward_list<int>& nexts(g.at(curr));
            for (auto i(nexts.begin()); i != nexts.end(); ++i) {
                int next(*i);
                degrees.at(next) -= 1;
                if (degrees.at(next) == 0) {
                    q.push(next);
                }
            }
        }
        return finished == numCourses;
    }
};
// @lc code=end

