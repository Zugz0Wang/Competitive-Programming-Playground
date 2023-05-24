// @lc app=leetcode id=2542 lang=cpp

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) { // Learned from solution
        const size_t size(nums1.size());
        vector<pair<int, int>> ps(size);
        for (size_t i(0); i < size; ++i) {
            pair<int, int>& curr(ps.at(i));
            curr.first = -nums2.at(i);
            curr.second = nums1.at(i);
        }
        sort(ps.begin(), ps.end());
        priority_queue<int> pq;
        long long max_val(0);
        long long total(0);
        for (pair<int, int>& p : ps) {
            //cout << p.first << ' ' << p.second << '\n';
            if (pq.size() >= k) {
                total += pq.top();
                // cout << pq.top() << '\n';
                pq.pop();
            }
            pq.push(-p.second);
            total += p.second;
            long long curr(total * (-p.first));
            if (pq.size() == k && curr > max_val) {
                max_val = curr;
            }
        }

        return max_val;
    }
};