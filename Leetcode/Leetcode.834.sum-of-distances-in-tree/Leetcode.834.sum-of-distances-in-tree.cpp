/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 *
 * https://leetcode.com/problems/sum-of-distances-in-tree/description/
 *
 * algorithms
 * Hard (53.64%)
 * Likes:    3944
 * Dislikes: 89
 * Total Accepted:    64.5K
 * Total Submissions: 112.7K
 * Testcase Example:  '6\n[[0,1],[0,2],[2,3],[2,4],[2,5]]'
 *
 * There is an undirected connected tree with n nodes labeled from 0 to n - 1
 * and n - 1 edges.
 * 
 * You are given the integer n and the array edges where edges[i] = [ai, bi]
 * indicates that there is an edge between nodes ai and bi in the tree.
 * 
 * Return an array answer of length n where answer[i] is the sum of the
 * distances between the i^th node in the tree and all other nodes.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
 * Output: [8,12,6,10,10,10]
 * Explanation: The tree is shown above.
 * We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
 * equals 1 + 1 + 2 + 2 + 2 = 8.
 * Hence, answer[0] = 8, and so on.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1, edges = []
 * Output: [0]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 2, edges = [[1,0]]
 * Output: [1,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 3 * 10^4
 * edges.length == n - 1
 * edges[i].length == 2
 * 0 <= ai, bi < n
 * ai != bi
 * The given input represents a valid tree.
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
struct info {
    int edge;
    int sum = -1;
    int num = -1;
    info(int e): edge(e) {};
};

struct node {
    int id;
    vector<info> next;
    
    node(int i): id(i), next({}) {};
};
class Solution {
public:
    vector<node> mp = {};
    int sum(int i) {
        const int kSize = mp[i].next.size();
        int ans = 0;
        for (int idx = 0; idx < kSize; idx++) {
            pair<int, int> res = sumEdge(i, idx);
            ans += res.first + res.second + 1;
        }
        return ans;
    }
    pair<int,int> sumEdge(int i, int edge) {
        info& data = mp[i].next.at(edge);
        int j = data.edge;
        int edgeSum = data.sum;
        int edgeNum = data.num;
        if (edgeSum >= 0) {
            return pair<int, int>(edgeSum, edgeNum);
        }
        const int kSize = mp[j].next.size();
        if (kSize == 1) {
            data.num = 0;
            data.sum = 0;
            return pair<int,int>(0,0);
        }
        data.sum = 0;
        data.num = 0;
        for (int idx = 0; idx < kSize; idx++) {
            int curr = mp[j].next.at(idx).edge;
            if (curr != i) {
                pair<int, int> res = sumEdge(j, idx);
                data.sum += res.first + res.second + 1;
                data.num += res.second + 1;
            }
        }

        return pair<int, int>(data.sum, data.num);
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            mp.push_back(node(i));
        }
        for (vector<int>& edge : edges) {
            int ai = edge.at(0);
            int bi = edge.at(1);
            mp[ai].next.push_back(info(bi));
            mp[bi].next.push_back(info(ai));
        }
        for (int i = 0; i < n; i++) {
            ans.at(i) = sum(i);
        }
        return ans;
    }
    // 2\n[[1,0]]
    // 1\n[]
    // 3\n[[0,1],[0,2]]
    // 4\n[[0,1],[0,2],[0,3]]
};
// @lc code=end

