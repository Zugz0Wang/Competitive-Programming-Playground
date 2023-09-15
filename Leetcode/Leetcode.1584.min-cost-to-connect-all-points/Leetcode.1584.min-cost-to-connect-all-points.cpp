class Solution { // Independently solved
public:
    int* uf;
    int size;
    struct Edge {
        int dis, from, to;
        Edge(int d, int f, int t): dis(d), from(f), to(t) {}
        bool operator<(const Edge& that) const {
            return dis < that.dis;
        }
    };
    int dis(const vector<int>& a, const vector<int>& b) {
        return abs(a.at(0) - b.at(0)) + abs(a.at(1) - b.at(1));
    }

    int find(int a) {
        int& curr(uf[a]);
        if (curr == a) {
            return curr;
        }
        curr = find(curr);
        return curr;
    }

    bool same(int a, int b) {
        int pa(find(a));
        int pb(find(b));
        return pa == pb;
    }

    void merge(int a, int b) {
        int pa(find(a));
        int pb(find(b));
        uf[pb] = pa;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        size = points.size();
        priority_queue<Edge> pq;
        for (int i(0); i < size; ++i) {
            for (int j(i + 1); j < size; ++j) {
                pq.push(Edge(-dis(points.at(i), points.at(j)), i, j));
            }
        }
        vector<int> uf_v(size);
        uf = uf_v.data();
        for (int i(0); i < size; ++i) {
            uf[i] = i;
        }
        int count(0);
        int ans(0);
        while (count < size - 1 && !(pq.empty())) {
            Edge curr(pq.top());
            pq.pop();
            int p_to(find(curr.to));
            int p_from(find(curr.from));
            // cout << p_to << ' ' << p_from << ' ' << curr.dis << '\n';
            if (p_to != p_from) {
                uf[p_from] = p_to;
                ans -= curr.dis;
                ++count;
            }
            // ++count;
        }
        return ans;
    }
};