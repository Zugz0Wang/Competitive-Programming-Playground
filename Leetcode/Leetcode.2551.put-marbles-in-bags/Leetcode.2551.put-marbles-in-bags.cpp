// @lc app=leetcode id=2551 lang=cpp
// @lc code=start
class Solution { // Independently solved
public:
    long long putMarbles(vector<int>& weights, int k) {
        const size_t size(weights.size());
        priority_queue<long long> pq_max;
        priority_queue<long long> pq_min;

        for (size_t i(0); i < size - 1; ++i) {
            pq_min.push(-weights.at(i) - weights.at(i + 1));
            pq_max.push(weights.at(i) + weights.at(i + 1));
        }
        
        long long max_sum(0);
        long long min_sum(0);
        for (int i(1); i < k; ++i) {
            max_sum += pq_max.top();
            min_sum -= pq_min.top();
            pq_max.pop();
            pq_min.pop();
        }
        // cout << max_sum << ' ' << min_sum << '\n';
        return max_sum - min_sum;
    }
};
// @lc code=end