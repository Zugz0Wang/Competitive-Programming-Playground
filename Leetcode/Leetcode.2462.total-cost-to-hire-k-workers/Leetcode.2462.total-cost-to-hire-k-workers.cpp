// @lc app=leetcode id=1575 lang=cpp
// @lc code=start
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) { // Independently solved
        const size_t size(costs.size());
        size_t begin(0);
        size_t last(size - 1);
        long long ans(0);
        priority_queue<int> pq1;
        priority_queue<int> pq2;
        for (int i(0); i < candidates && begin <= last; ++i) {
            pq1.push(-costs.at(begin));
            begin += 1;
            
        }
        for (int i(0); i < candidates && begin <= last; ++i) {
            pq2.push(-costs.at(last));
            last -= 1;
        }
        for (int i(0); i < k; ++i) {
            if (pq2.empty() || (!pq1.empty() && pq1.top() >= pq2.top())) {
                ans -= pq1.top();
                // cout << pq1.top() << '\n';
                pq1.pop();
                if (begin <= last) {
                    pq1.push(-costs.at(begin));
                    begin += 1;
                }
            } else {
                ans -= pq2.top();
                // cout << pq2.top() << '\n';
                pq2.pop();
                if (begin <= last) {
                    pq2.push(-costs.at(last));
                    last -= 1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end