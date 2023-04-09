/*
 * @lc app=leetcode id=1857 lang=cpp
 *
 * [1857] Largest Color Value in a Directed Graph
 *
 * https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/
 *
 * algorithms
 * Hard (40.15%)
 * Likes:    710
 * Dislikes: 21
 * Total Accepted:    16.1K
 * Total Submissions: 38.9K
 * Testcase Example:  '"abaca"\n[[0,1],[0,2],[2,3],[3,4]]'
 *
 * There is a directed graph of n colored nodes and m edges. The nodes are
 * numbered from 0 to n - 1.
 * 
 * You are given a string colors where colors[i] is a lowercase English letter
 * representing the color of the i^th node in this graph (0-indexed). You are
 * also given a 2D array edges where edges[j] = [aj, bj] indicates that there
 * is a directed edge from node aj to node bj.
 * 
 * A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk
 * such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The
 * color value of the path is the number of nodes that are colored the most
 * frequently occurring color along that path.
 * 
 * Return the largest color value of any valid path in the given graph, or -1
 * if the graph contains a cycle.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
 * Output: 3
 * Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a"
 * (red in the above image).
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: colors = "a", edges = [[0,0]]
 * Output: -1
 * Explanation: There is a cycle from 0 to 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == colors.length
 * m == edges.length
 * 1 <= n <= 10^5
 * 0 <= m <= 10^5
 * colors consists of lowercase English letters.
 * 0 <= aj, bj < n
 * 
 */

#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution { // Independently solved
public:
    struct Node {
        int val;
        vector<int> nexts;

        bool visited; // Marking whether the node has been visited during the current trip. (To test cycles)
        bool saved; // Marking whether the node has been visited, so that we can directly use its memorized information.
        int color; // Its color.
        int* record; // The max color value of paths starting at this node.

        Node(): val(-1), color(-1), visited(false), saved(false) {
            record = new int[26];
            for(int i(0); i < 26; ++i) {
                record[i] = 0;
            }
        }
        
        ~Node() {
            delete[] record;
        }
    };

    Node* graph;
    int n;
    int max;

    void dfs(int i) {
        Node& curr(graph[i]);

        if (curr.visited) { // We have found a cycle.
            max = -1;
            return;
        }

        if (curr.saved) { // We have visited it in another path. And so we can directly use its stored information.
            return;
        }

        curr.visited = true;
        curr.saved = true;

        for (int next_idx: curr.nexts) {
            // cout << next_idx << "!\n";
            dfs(next_idx);
            if (max == -1) { // A children have found a cycle.
                return;
            }
            Node& next(graph[next_idx]);
            for (int color(0); color < 26; ++color) { // If a sub child has a large color value of a color.
                int& curr_color(curr.record[color]);
                int& next_color(next.record[color]);
                if (next_color > curr_color) {
                    curr_color = next_color;
                }
            }

        }

        curr.record[curr.color] += 1; // Also counting itself.

        for (int color(0); color < 26; ++color) {
            int& curr_color(curr.record[color]);
            
            if (curr_color > max) {
                max = curr_color;
            }
        }
        curr.visited = false;
        return;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        n = colors.size();
        graph = new Node[n];
        for (int i(0); i < n; ++i) { // Initialize vertices.
            Node& curr(graph[i]);
            curr.val = i;
            int color(colors.at(i) - 'a');
            curr.color = color;
        }

        for (vector<int>& edge: edges) {
            graph[edge.at(0)].nexts.push_back(edge.at(1)); // Build edges.
        }
        
        for (int i(0); i < n; ++i) {
            dfs(i);
        }

        delete[] graph;
        return max;
    }
};
// @lc code=end

