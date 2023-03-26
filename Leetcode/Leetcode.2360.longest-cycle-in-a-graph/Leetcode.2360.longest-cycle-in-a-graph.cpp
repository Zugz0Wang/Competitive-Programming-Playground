/*
 * @lc app=leetcode id=2360 lang=cpp
 *
 * [2360] Longest Cycle in a Graph
 *
 * https://leetcode.com/problems/longest-cycle-in-a-graph/description/
 *
 * algorithms
 * Hard (37.71%)
 * Likes:    843
 * Dislikes: 13
 * Total Accepted:    21.6K
 * Total Submissions: 52.1K
 * Testcase Example:  '[3,3,4,2,3]'
 *
 * You are given a directed graph of n nodes numbered from 0 to n - 1, where
 * each node has at most one outgoing edge.
 * 
 * The graph is represented with a given 0-indexed array edges of size n,
 * indicating that there is a directed edge from node i to node edges[i]. If
 * there is no outgoing edge from node i, then edges[i] == -1.
 * 
 * Return the length of the longest cycle in the graph. If no cycle exists,
 * return -1.
 * 
 * A cycle is a path that starts and ends at the same node.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: edges = [3,3,4,2,3]
 * Output: 3
 * Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
 * The length of this cycle is 3, so 3 is returned.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: edges = [2,-1,3,1]
 * Output: -1
 * Explanation: There are no cycles in this graph.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == edges.length
 * 2 <= n <= 10^5
 * -1 <= edges[i] < n
 * edges[i] != i
 * 
 * 
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestCycle(vector<int>& edges) { // Original
        const int n(edges.size());
        vector<pair<int, int>> visited(n, pair<int, int>(-1, -1));

        int ans = -1;
        
        for (int i(0); i < n; ++i) {
            int length(0);
            int curr(i);
            if (visited.at(curr).first >= 0) {
                continue;
            }
            while (edges.at(curr) != -1) {
                // cout << curr << ' ';
                pair<int, int>& info = visited.at(curr);
                if (info.first >= 0 && info.second == i) {
                    // cout << '!';
                    int curr_length = length - info.first;
                    if (curr_length > ans) {
                        ans = curr_length;
                    }
                    break;
                } else if (info.first == -1) {
                    info.first = length;
                    info.second = i;
                } else {
                    break;
                }
                ++length;
                curr = edges.at(curr);
            }
        }

        return ans;
    }
};
// @lc code=end

