/*
 * @lc app=leetcode id=1489 lang=cpp
 *
 * [1489] Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
 *
 * https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/
 *
 * algorithms
 * Hard (52.96%)
 * Likes:    760
 * Dislikes: 64
 * Total Accepted:    13.6K
 * Total Submissions: 24.9K
 * Testcase Example:  '5\n[[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]'
 *
 * Given a weighted undirected connected graph with n vertices numbered from 0
 * to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a
 * bidirectional and weighted edge between nodes ai and bi. A minimum spanning
 * tree (MST) is a subset of the graph's edges that connects all vertices
 * without cycles and with the minimum possible total edge weight.
 * 
 * Find all the critical and pseudo-critical edges in the given graph's minimum
 * spanning tree (MST). An MST edge whose deletion from the graph would cause
 * the MST weight to increase is called a critical edge. On the other hand, a
 * pseudo-critical edge is that which can appear in some MSTs but not all.
 * 
 * Note that you can return the indices of the edges in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 5, edges =
 * [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
 * Output: [[0,1],[2,3,4,5]]
 * Explanation: The figure above describes the graph.
 * The following figure shows all the possible MSTs:
 * 
 * Notice that the two edges 0 and 1 appear in all MSTs, therefore they are
 * critical edges, so we return them in the first list of the output.
 * The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are
 * considered pseudo-critical edges. We add them to the second list of the
 * output.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
 * Output: [[],[0,1,2,3]]
 * Explanation: We can observe that since all 4 edges have equal weight,
 * choosing any 3 edges from the given 4 will yield an MST. Therefore all 4
 * edges are pseudo-critical.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 100
 * 1 <= edges.length <= min(200, n * (n - 1) / 2)
 * edges[i].length == 3
 * 0 <= ai < bi < n
 * 1 <= weighti <= 1000
 * All pairs (ai, bi) are distinct.
 * 
 * 
 */

// @lc code=start
class Solution { // Hinted
public:

    int n;
    size_t size;

    int* uf;

    int find(int i) {
        int& curr(uf[i]);
        if (curr == i) {
            return curr;
        }
        curr = find(curr);
        return curr;
    }

    void merge(int a, int b) {
        int pa(find(a));
        int pb(find(b));
        uf[pb] = pa;
    }

    void reset() {
        for (int i(0); i < n; ++i) {
            uf[i] = i;
        }
    }

    int MST(int not_use, int ans, int count) {
        
        int edge_i(0);
        
        while (count < n && edge_i < size) {
            const Edge& curr(edges[edge_i]);
            if (curr.i == not_use) {
                ++edge_i;
                continue;
            }
            int pa(find(curr.a));
            int pb(find(curr.b));
            if (pa != pb) {
                ans += curr.w;
                merge(pa, pb);
                ++count;
            }
            ++edge_i;
        }

        reset();
        // cout << count << '\n';
        if (count < n) {
            ans = -ans;
        }
        return ans;
    }

    struct Edge {
        int a;
        int b;
        int w;
        int i;
        Edge(): i(0), a(0), b(0), w(0) {}
        void fromVector(const int idx, const vector<int>& edge) {
            i = idx;
            a = edge.at(0);
            b = edge.at(1);
            w = edge.at(2);
        }
        bool operator<(const Edge& other) const {
            return w < other.w;
        }
    };
    Edge* edges;
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n_, vector<vector<int>>& edges_) {
        n = n_;
        uf = new int[n];
        size = edges_.size();
        edges = new Edge[size];
        for (size_t i(0); i < size; ++i) {
            edges[i].fromVector(i, edges_.at(i));
        }
        sort(edges + 0, edges + size);
        
        vector<vector<int>> ans{{}, {}};
        vector<int>& c(ans.at(0));
        vector<int>& pc(ans.at(1));
        reset();
        int min(MST(-1, 0, 1));
        for (size_t i(0); i < size; ++i) {
            const Edge& curr(edges[i]);
            merge(curr.a, curr.b);
            int curr_add(MST(curr.i, curr.w, 2));
            // cout << curr.i << ' ' << curr_add << '\n';
            if (curr_add <= 0 || curr_add > min) {
                continue;
            }
            int curr_remove(MST(curr.i, 0, 1));
            if (curr_remove <= 0 || curr_remove > min) {
                c.push_back(curr.i);
            } else {
                pc.push_back(curr.i);
            }
        }

        delete[] edges;
        delete[] uf;
        return ans;
    }
};
// @lc code=end

