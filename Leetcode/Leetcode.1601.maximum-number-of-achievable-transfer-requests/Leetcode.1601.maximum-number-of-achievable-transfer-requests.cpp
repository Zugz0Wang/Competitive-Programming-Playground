// @lc app=leetcode id=1601 lang=cpp
// @lc code=start
class Solution { // Learned from solution.
public:
    int maximumRequests(int size, vector<vector<int>>& requests) {
        int n(requests.size());
        int* nodes = new int[size];
        int ans(0);
        for (int state((2 << n) - 1); state > 0; --state) {
            for (int i(0); i < size; ++i) {
                nodes[i] = 0;
            }
            int curr(state);
            int select(0);
            for (int i(0); i < n; ++i) {
                if ((curr & 1) == 0) {
                    curr = curr >> 1;
                    continue;
                } else {
                    curr = curr >> 1;
                }
                select += 1;
                vector<int>& request(requests.at(i));
                int x(request.at(0));
                int y(request.at(1));
                nodes[x] -= 1;
                nodes[y] += 1;
            }
            bool flag(true);
            for (int i(0); i < size; ++i) {
                if (nodes[i] != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag && select > ans) {
                ans = select;
            }
        }
        return ans;
    }
};
// @lc code=end