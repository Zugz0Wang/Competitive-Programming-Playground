/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 *
 * https://leetcode.com/problems/find-if-path-exists-in-graph/description/
 *
 * algorithms
 * Easy (50.50%)
 * Likes:    1786
 * Dislikes: 97
 * Total Accepted:    157.7K
 * Total Submissions: 311.6K
 * Testcase Example:  '3\n[[0,1],[1,2],[2,0]]\n0\n2'
 *
 * There is a bi-directional graph with n vertices, where each vertex is
 * labeled from 0 to n - 1 (inclusive). The edges in the graph are represented
 * as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a
 * bi-directional edge between vertex ui and vertex vi. Every vertex pair is
 * connected by at most one edge, and no vertex has an edge to itself.
 * 
 * You want to determine if there is a valid path that exists from vertex
 * source to vertex destination.
 * 
 * Given edges and the integers n, source, and destination, return true if
 * there is a valid path from source to destination, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
 * Output: true
 * Explanation: There are two paths from vertex 0 to vertex 2:
 * - 0 → 1 → 2
 * - 0 → 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0,
 * destination = 5
 * Output: false
 * Explanation: There is no path from vertex 0 to vertex 5.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 2 * 10^5
 * 0 <= edges.length <= 2 * 10^5
 * edges[i].length == 2
 * 0 <= ui, vi <= n - 1
 * ui != vi
 * 0 <= source, destination <= n - 1
 * There are no duplicate edges.
 * There are no self edges.
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int set[200000];
    int look(int idx) {
        if (set[idx] == idx) {
            return idx;
        }
        int root = look(set[idx]);
        set[idx] = root;
        // while (set[idx] != idx) {
        //     idx = set[idx];
        // }
        return root;
    }

    void uni(int i0, int i1) {
        i0 = look(i0);
        i1 = look(i1);
        if (i0 < i1) {
            set[i1] = i0;
        } else {
            set[i0] = i1;
        }   
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for (int i = 0; i < n; i++) {
            set[i] = i;
        }
        const int kSize = edges.size();
        for (int i = 0; i < kSize; i++) {
            uni(edges.at(i).at(0), edges.at(i).at(1));
        }
        return look(source) == look(destination);
    }
    //6\n[[0,1],[0,2],[3,5],[5,4],[4,3]]\n0\n5
    //10\n[[0,7],[0,8],[6,1],[2,0],[0,4],[5,8],[4,7],[1,3],[3,5],[6,5]]\n7\n5
};
// @lc code=end

