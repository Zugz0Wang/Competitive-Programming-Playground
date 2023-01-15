/*
 * @lc app=leetcode id=1443 lang=cpp
 *
 * [1443] Minimum Time to Collect All Apples in a Tree
 *
 * https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/
 *
 * algorithms
 * Medium (55.90%)
 * Likes:    1389
 * Dislikes: 119
 * Total Accepted:    37.1K
 * Total Submissions: 65.3K
 * Testcase Example:  '7\n' +
  '[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]\n' +
  '[false,false,true,false,true,true,false]'
 *
 * Given an undirected tree consisting of n vertices numbered from 0 to n-1,
 * which has some apples in their vertices. You spend 1 second to walk over one
 * edge of the tree. Return the minimum time in seconds you have to spend to
 * collect all apples in the tree, starting at vertex 0 and coming back to this
 * vertex.
 * 
 * The edges of the undirected tree are given in the array edges, where
 * edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and
 * bi. Additionally, there is a boolean array hasApple, where hasApple[i] =
 * true means that vertex i has an apple; otherwise, it does not have any
 * apple.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple =
 * [false,false,true,false,true,true,false]
 * Output: 8 
 * Explanation: The figure above represents the given tree where red vertices
 * have an apple. One optimal path to collect all apples is shown by the green
 * arrows.  
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple =
 * [false,false,true,false,false,true,false]
 * Output: 6
 * Explanation: The figure above represents the given tree where red vertices
 * have an apple. One optimal path to collect all apples is shown by the green
 * arrows.  
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple =
 * [false,false,false,false,false,false,false]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * edges.length == n - 1
 * edges[i].length == 2
 * 0 <= ai < bi <= n - 1
 * fromi < toi
 * hasApple.length == n
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> apple;
    vector<bool> visited;

    int dfs(int curr) {
        visited.at(curr) = true;

        vector<int>& nexts = graph.at(curr);
        bool hasApple = apple.at(curr);
        int time = 0;
        

        for (int next : nexts) {
            if (visited.at(next) == false) {
                time += dfs(next);
            }
        }

        visited.at(curr) = false;

        if (time > 0 || hasApple) {
            time += 2;
        }
        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        apple = hasApple;
        visited.resize(n, false);
        graph.resize(n, {});
        for (vector<int>& edge : edges) {
            int curr = edge.at(0);
            int next = edge.at(1);
            graph.at(curr).push_back(next);
            graph.at(next).push_back(curr);
        }

        int time = dfs(0);
        if (time == 0) {
            return 0;
        }
        return time - 2;

    }
    // 7\n[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]\n[false,false,true,false,false,true,false]
};
// @lc code=end

