#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) { // Original
        map<int, vector<pair<int, int>>> graph;
        for (auto road: roads) {
            int from(road.at(0));
            int to(road.at(1));
            int cost(road.at(2));
            if (graph.count(from) == 0) {
                graph.insert(pair<int, vector<pair<int, int>>>(from, {}));
            }
            if (graph.count(to) == 0) {
                graph.insert(pair<int, vector<pair<int, int>>>(to, {}));
            }
            graph.at(to).push_back(pair<int, int>(from, cost));
            graph.at(from).push_back(pair<int, int>(to, cost));
        }
        queue<int> wait;
        set<int> visited;
        visited.insert(1);
        wait.push(1);
        int ans(100000);
        while (!wait.empty()) {
            int curr = wait.front();
            wait.pop();
            for (auto edge: graph.at(curr)) {
                if (visited.count(edge.first) == 0) {
                    wait.push(edge.first);
                    visited.insert(edge.first);
                }
                if (edge.second < ans) {
                    ans = edge.second;
                }
            }
        }
        return ans;
    }
};