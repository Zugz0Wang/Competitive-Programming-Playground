/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 *
 * https://leetcode.com/problems/shortest-path-with-alternating-colors/description/
 *
 * algorithms
 * Medium (42.62%)
 * Likes:    1758
 * Dislikes: 86
 * Total Accepted:    49.4K
 * Total Submissions: 114.7K
 * Testcase Example:  '3\n[[0,1],[1,2]]\n[]'
 *
 * You are given an integer n, the number of nodes in a directed graph where
 * the nodes are labeled from 0 to n - 1. Each edge is red or blue in this
 * graph, and there could be self-edges and parallel edges.
 * 
 * You are given two arrays redEdges and blueEdges where:
 * 
 * 
 * redEdges[i] = [ai, bi] indicates that there is a directed red edge from node
 * ai to node bi in the graph, and
 * blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from
 * node uj to node vj in the graph.
 * 
 * 
 * Return an array answer of length n, where each answer[x] is the length of
 * the shortest path from node 0 to node x such that the edge colors alternate
 * along the path, or -1 if such a path does not exist.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
 * Output: [0,1,-1]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
 * Output: [0,1,-1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 100
 * 0 <= redEdges.length, blueEdges.length <= 400
 * redEdges[i].length == blueEdges[j].length == 2
 * 0 <= ai, bi, uj, vj < n
 * 
 * 
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start

struct node {
    vector<int> red;
    vector<int> blue;
};

struct wait {
    bool color;
    int idx;
    wait(bool c, int i): color(c), idx(i) {}
};

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<node> graph(n);
        
        for (auto edge : redEdges) {
            int a = edge.at(0);
            int b = edge.at(1);
            graph.at(a).red.push_back(b);
        }
        for (auto edge : blueEdges) {
            int a = edge.at(0);
            int b = edge.at(1);
            graph.at(a).blue.push_back(b);
        }
        vector<bool> red(n, false);
        vector<bool> blue(n, false);
        vector<int> ans(n ,-1);
        queue<wait> waitlist;

        waitlist.push(wait(true, 0));
        waitlist.push(wait(false,0));
        red.at(0) = true;
        blue.at(0) = true;
        int dis = 0;
        while (!waitlist.empty()) {
            int size = waitlist.size();
            while (size > 0) {
                int curr = waitlist.front().idx;
                bool isred = waitlist.front().color;
                if (ans.at(curr) == -1) {
                    ans.at(curr) = dis;
                }
                
                waitlist.pop();
                if (isred) {
                    for (int next : graph.at(curr).blue) {
                        if (blue.at(next) == false) {
                            blue.at(next) = true;
                            waitlist.push(wait(false, next));
                        }
                    }
                } else {
                    for (int next : graph.at(curr).red) {
                        if (red.at(next) == false) {
                            red.at(next) = true;
                            waitlist.push(wait(true, next));
                        }
                    }
                }
                size--;
            }
            dis++;
        }
        return ans;
    }
};
// @lc code=end

