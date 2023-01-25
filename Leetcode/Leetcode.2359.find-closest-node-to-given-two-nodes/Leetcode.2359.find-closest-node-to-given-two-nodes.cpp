// @lc app=leetcode id=2359 lang=cpp
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    // Adapted directly from Leetcode solution
    vector<int> edges;
    const int limit = numeric_limits<int>::max();
    void bfs(int root, vector<int>& dist) {
        int n = edges.size();
        queue<int> wait;
        wait.push(root);

        vector<bool> visit(n);
        dist[root] = 0;

        while (!wait.empty()) {
            int node = wait.front();
            wait.pop();

            // if (dist[node] != limit) {
            //     continue;
            // } It seems that is useless
            
            int next = edges[node];
            int next_dis = 1 + dist[node];
            if (next != -1 && dist[next] > next_dis) {
                dist[next] = next_dis;
                wait.push(next);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges0, int node1, int node2) {
        edges = edges0;
        int n = edges.size();
        vector<int> dist1(n, limit), dist2(n, limit);

        bfs(node1, dist1);
        bfs(node2, dist2);

        int minDistNode = -1, minDistTillNow = limit;
        for (int currNode = 0; currNode < n; currNode++) {
            if (minDistTillNow > max(dist1[currNode], dist2[currNode])) {
                minDistNode = currNode;
                minDistTillNow = max(dist1[currNode], dist2[currNode]);
            }
        }

        return minDistNode;
    }
};
// @lc code=end