/*
 * @lc app=leetcode id=1579 lang=cpp
 *
 * [1579] Remove Max Number of Edges to Keep Graph Fully Traversable
 *
 * https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/
 *
 * algorithms
 * Hard (52.14%)
 * Likes:    984
 * Dislikes: 11
 * Total Accepted:    19.4K
 * Total Submissions: 36.1K
 * Testcase Example:  '4\n[[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]'
 *
 * Alice and Bob have an undirected graph of n nodes and three types of
 * edges:
 * 
 * 
 * Type 1: Can be traversed by Alice only.
 * Type 2: Can be traversed by Bob only.
 * Type 3: Can be traversed by both Alice and Bob.
 * 
 * 
 * Given an array edges where edges[i] = [typei, ui, vi] represents a
 * bidirectional edge of type typei between nodes ui and vi, find the maximum
 * number of edges you can remove so that after removing the edges, the graph
 * can still be fully traversed by both Alice and Bob. The graph is fully
 * traversed by Alice and Bob if starting from any node, they can reach all
 * other nodes.
 * 
 * Return the maximum number of edges you can remove, or return -1 if Alice and
 * Bob cannot fully traverse the graph.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
 * Output: 2
 * Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will
 * still be fully traversable by Alice and Bob. Removing any additional edge
 * will not make it so. So the maximum number of edges we can remove is 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
 * Output: 0
 * Explanation: Notice that removing any edge will not make the graph fully
 * traversable by Alice and Bob.
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
 * Output: -1
 * Explanation: In the current graph, Alice cannot reach node 4 from the other
 * nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the
 * graph fully traversable.
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * 1 <= edges.length <= min(10^5, 3 * n * (n - 1) / 2)
 * edges[i].length == 3
 * 1 <= typei <= 3
 * 1 <= ui < vi <= n
 * All tuples (typei, ui, vi) are distinct.
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution { // Independently solved(hinted by the title of solution)
public:

    size_t find(size_t i, size_t* uf) {
        size_t& curr(uf[i]);
        if (curr == i) {
            return curr;
        }
        // cout << curr << '\n';
        curr = find(curr, uf);
        return curr;
    }

    bool uni(size_t u, size_t v, size_t* uf) {
        size_t p_u(find(u, uf));
        size_t p_v(find(v, uf));

        if (p_u == p_v) {
            return false;
        }

        uf[p_v] = p_u;
        return true;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [&](const vector<int>& a, const vector<int>& b){return a.at(0) > b.at(0);});
        size_t* uf_a = new size_t[n + 1];
        size_t* uf_b = new size_t[n + 1];

        int count_a(n);
        int count_b(n);
        size_t N(n);
        for (size_t i(0); i < N + 1; ++i) {
            uf_a[i] = i;
            uf_b[i] = i;
        }

        const size_t kSize(edges.size());
        int use(0);
        for (size_t i(0); i < kSize && (count_a > 1 || count_b > 1); ++i) {
            const vector<int>& edge(edges.at(i));
            const int type(edge.at(0));
            const int u(edge.at(1));
            const int v(edge.at(2));
            // cout << type << ' ' << u << ' ' << v << '\n';
            if (type == 3) {
                bool use_a(uni(u, v, uf_a));
                bool use_b(uni(u, v, uf_b));
                if (use_a) {
                    --count_a;
                }
                if (use_b) {
                    --count_b;
                }
                if (use_a || use_b) {
                    ++use;
                }
            } else if (type == 1) {
                if (uni(u, v, uf_a)) {
                    --count_a;
                    ++use;
                }
            } else {
                if (uni(u, v, uf_b)) {
                    --count_b;
                    ++use;
                }
            }
        }

        delete[] uf_a;
        delete[] uf_b;

        if (count_a > 1 || count_b > 1) {
            return -1;
        }

        return kSize - use;
    }
};
// @lc code=end

