class Solution { // Busy today, will be back
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int size(graph.size());
        const int full_mask(((1 << size) - 1) << 4);
        const int node_mask((1 << 4) - 1);
        
        vector<bool> visited(full_mask + node_mask);
        queue<int> q;
        for (int i(0); i < size; ++i) {
            int curr_mask(((16 << i)) + i);
            visited[curr_mask] = true;
            q.push(curr_mask);
        }
        int dis(0);
        while (!q.empty()) {
            int curr_size(q.size());
            for (int i(0); i < curr_size; ++i) {
                int curr_mask(q.front());
                q.pop();
                int visited_mask(curr_mask & full_mask);
                int node(curr_mask & node_mask);

                if (visited_mask == full_mask) {
                    return dis;
                }
                // cout << bitset<>() << '\n';
                // return 0;
                const vector<int>& nexts(graph.at(node));
                for (int next : nexts) {
                    int next_visited_mask(visited_mask | (16 << next));
                    int next_mask(next_visited_mask + next);
                    if (visited[next_mask]) {
                        continue;
                    }
                    visited[next_mask] = true;
                    q.push(next_mask);
                }
            }
            ++dis;
        }
        
        return 404;
    }
};