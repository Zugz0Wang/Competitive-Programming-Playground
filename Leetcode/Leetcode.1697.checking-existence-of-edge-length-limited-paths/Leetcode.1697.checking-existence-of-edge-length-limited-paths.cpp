/*
 * @lc app=leetcode id=1697 lang=cpp
 *
 * [1697] Checking Existence of Edge Length Limited Paths
 *
 * https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/description/
 *
 * algorithms
 * Hard (49.81%)
 * Likes:    834
 * Dislikes: 17
 * Total Accepted:    15.4K
 * Total Submissions: 28.9K
 * Testcase Example:  '3\n[[0,1,2],[1,2,4],[2,0,8],[1,0,16]]\n[[0,1,2],[0,2,5]]'
 *
 * An undirected graph of n nodes is defined by edgeList, where edgeList[i] =
 * [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi.
 * Note that there may be multiple edges between two nodes.
 * 
 * Given an array queries, where queries[j] = [pj, qj, limitj], your task is to
 * determine for each queries[j] whether there is a path between pj and qj such
 * that each edge on the path has a distance strictly less than limitj .
 * 
 * Return a boolean array answer, where answer.length == queries.length and the
 * j^th value of answer is true if there is a path for queries[j] is true, and
 * false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries =
 * [[0,1,2],[0,2,5]]
 * Output: [false,true]
 * Explanation: The above figure shows the given graph. Note that there are two
 * overlapping edges between 0 and 1 with distances 2 and 16.
 * For the first query, between 0 and 1 there is no path where each distance is
 * less than 2, thus we return false for this query.
 * For the second query, there is a path (0 -> 1 -> 2) of two edges with
 * distances less than 5, thus we return true for this query.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries =
 * [[0,4,14],[1,4,13]]
 * Output: [true,false]
 * Exaplanation: The above figure shows the given graph.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 10^5
 * 1 <= edgeList.length, queries.length <= 10^5
 * edgeList[i].length == 3
 * queries[j].length == 3
 * 0 <= ui, vi, pj, qj <= n - 1
 * ui != vi
 * pj != qj
 * 1 <= disi, limitj <= 10^9
 * There may be multiple edges between two nodes.
 * 
 * 
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution { // Learned
public:
    struct Edge {
        int w;
        int u;
        int v;
        Edge(vector<int> e): w(e.at(2)), u(e.at(0)), v(e.at(1)) {}
        bool operator<(const Edge& that) const {
            if (w == that.w) {
                if (u == that.u) {
                    return v > that.v;
                }
                return u > that.u;
            }
            return w > that.w;
        }
    };

    size_t* uf;

    size_t find(size_t i) {
        size_t& curr(uf[i]);
        if (curr == i) {
            return i;
        }
        curr = find(curr);
        return curr;
    }

    bool uni(size_t i, size_t j) {
        size_t p_i(find(i));
        size_t p_j(find(j));
        if (p_i == p_j) {
            return false;
        }
        uf[p_j] = p_i;
        return true;
    }


    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        priority_queue<Edge> pq;
        uf = new size_t[n];

        for (int i(0); i < n; ++i) {
            uf[i] = i;
        }

        const size_t kSize(queries.size());
        for (size_t i(0); i < kSize; ++i) {
          queries.at(i).push_back(i);
        }

        sort(queries.begin(), queries.end(), [&](const vector<int>&a, vector<int>&b) { return a.at(2) < b.at(2); });

        for (const vector<int>& e : edgeList) {
            pq.push(Edge(e));
        }
       
        
        vector<bool> ans(kSize, false);

        for (size_t i(0); i < kSize; ++i) {
            const vector<int>& q(queries.at(i));
            const size_t a(q.at(0));
            const size_t b(q.at(1));
            const size_t w(q.at(2));
            const size_t id(q.at(3));
            while (!pq.empty() && pq.top().w < w) {
                const Edge& e(pq.top());
                uni(e.u, e.v);
                pq.pop();
            }
            if (find(a) == find(b)) {
                ans.at(id) = true;
            }
        }

        delete[] uf;
        uf = nullptr;
        return ans;
    }
};
// @lc code=end

