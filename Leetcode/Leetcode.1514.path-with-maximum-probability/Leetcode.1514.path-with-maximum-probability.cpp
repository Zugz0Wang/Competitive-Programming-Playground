/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 *
 * https://leetcode.com/problems/path-with-maximum-probability/description/
 *
 * algorithms
 * Medium (47.86%)
 * Likes:    1594
 * Dislikes: 33
 * Total Accepted:    59.6K
 * Total Submissions: 123K
 * Testcase Example:  '3\n[[0,1],[1,2],[0,2]]\n[0.5,0.5,0.2]\n0\n2'
 *
 * You are given an undirected weighted graph of n nodes (0-indexed),
 * represented by an edge list where edges[i] = [a, b] is an undirected edge
 * connecting the nodes a and b with a probability of success of traversing
 * that edge succProb[i].
 * 
 * Given two nodes start and end, find the path with the maximum probability of
 * success to go from start to end and return its success probability.
 * 
 * If there is no path from start to end, return 0. Your answer will be
 * accepted if it differs from the correct answer by at most 1e-5.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start =
 * 0, end = 2
 * Output: 0.25000
 * Explanation: There are two paths from start to end, one having a probability
 * of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start =
 * 0, end = 2
 * Output: 0.30000
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
 * Output: 0.00000
 * Explanation: There is no path between 0 and 2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 10^4
 * 0 <= start, end < n
 * start != end
 * 0 <= a, b < n
 * a != b
 * 0 <= succProb.length == edges.length <= 2*10^4
 * 0 <= succProb[i] <= 1
 * There is at most one edge between every two nodes.
 * 
 * 
 */

// @lc code=start
class PQ {
    double* arr;
    bool* popped;
    int N;
    int top_idx;
    int s;
    void select() {
        top_idx = 0;
        double top_val = 0;
        bool wait(true);
        for (int i(0); i < N; ++i) {
            if (!popped[i] && (wait || arr[i] > top_val)) {
                top_val = arr[i];
                top_idx = i;
                wait = false;
            }
        }
    }

    public:
    PQ(int n) {
        N = n;
        s = n;
        top_idx = n;
        arr = new double[N];
        popped = new bool[N];
        for (int i(0); i < N; ++i) {
            arr[i] = 0;
            popped[i] = false;
        }
    }

    int get_pop_top() {
        select();
        s -= 1;
        popped[top_idx] = true;
        return top_idx;
    }

    double get(int i) {
        return arr[i];
    }

    int size() {
        return s;
    }

    void update(int i, double v) {
        arr[i] = v;
    }

    ~PQ() {
        delete[] arr;
        delete[] popped;
    }
};

class Solution { // Independently solved; using normal array instead of heap
public:
    struct Edge {
        int to;
        double prob;
        Edge(int t_, double p_): to(t_), prob(p_) {}
    };
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<Edge>> g(n);
        for (size_t i(0); i < succProb.size(); ++i) {
            const vector<int>& edge(edges.at(i));
            int x(edge.at(0));
            int y(edge.at(1));
            double p(succProb.at(i));
            g.at(x).push_back(Edge(y, p));
            g.at(y).push_back(Edge(x, p));
        }
        PQ pq(n);
        pq.update(start, 1);
        while (pq.size() > 0) {
            int curr_idx(pq.get_pop_top());
            
            double curr_prob(pq.get(curr_idx));
            // cout << curr_idx << ' ' << curr_prob << '\n';
            if (curr_idx == end) {
                return curr_prob;
            }
            const vector<Edge>& nexts(g.at(curr_idx));
            for (const Edge& next : nexts) {
                // cout << next.prob << ' ';
                if (next.prob * curr_prob > pq.get(next.to)) {
                    pq.update(next.to, next.prob * curr_prob);
                }
            }
            // cout << '\n';
        }
        return 0;
    }
};
// @lc code=end

