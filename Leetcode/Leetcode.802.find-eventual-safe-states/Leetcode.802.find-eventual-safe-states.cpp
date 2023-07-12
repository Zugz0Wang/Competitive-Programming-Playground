/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 *
 * https://leetcode.com/problems/find-eventual-safe-states/description/
 *
 * algorithms
 * Medium (53.86%)
 * Likes:    4120
 * Dislikes: 373
 * Total Accepted:    141.7K
 * Total Submissions: 243.5K
 * Testcase Example:  '[[1,2],[2,3],[5],[0],[5],[],[]]'
 *
 * There is a directed graph of n nodes with each node labeled from 0 to n - 1.
 * The graph is represented by a 0-indexed 2D integer array graph where
 * graph[i] is an integer array of nodes adjacent to node i, meaning there is
 * an edge from node i to each node in graph[i].
 * 
 * A node is a terminal node if there are no outgoing edges. A node is a safe
 * node if every possible path starting from that node leads to a terminal node
 * (or another safe node).
 * 
 * Return an array containing all the safe nodes of the graph. The answer
 * should be sorted in ascending order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
 * Output: [2,4,5,6]
 * Explanation: The given graph is shown above.
 * Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either
 * of them.
 * Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
 * 
 * Example 2:
 * 
 * 
 * Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
 * Output: [4]
 * Explanation:
 * Only node 4 is a terminal node, and every path starting at node 4 leads to
 * node 4.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == graph.length
 * 1 <= n <= 10^4
 * 0 <= graph[i].length <= n
 * 0 <= graph[i][j] <= n - 1
 * graph[i] is sorted in a strictly increasing order.
 * The graph may contain self-loops.
 * The number of edges in the graph will be in the range [1, 4 * 10^4].
 * 
 * 
 */

// @lc code=start
class Solution { // Idea refined from solution
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const size_t size(graph.size());
        vector<vector<int>> back(size);
        vector<bool> safe(size, false);
        vector<int> degrees(size, 0);

        queue<int> q;

        for (size_t i(0); i < size; ++i) {
            const vector<int>& nexts(graph.at(i));
            
            for (int next : nexts) {
                back.at(next).push_back(i);
            }
        }

        for (size_t i(0); i < size; ++i) {
            degrees.at(i) = graph.at(i).size();
            if (degrees.at(i) == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            const size_t level_size(q.size());
            for (size_t i(0); i < level_size; ++i) {
                int curr(q.front());
                q.pop();
               
                safe.at(curr) = true;

                const vector<int>& backward(back.at(curr));
                for (int next : backward) {
                    int& next_d(degrees.at(next));
                    next_d -= 1;
                    if (next_d == 0) {
                        q.push(next);
                    }
                }
            }
        }

        vector<int> ans;
        for (size_t i(0); i < size; ++i) {
            if (safe.at(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

