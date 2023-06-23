// @lc app=leetcode id=1027 lang=cpp
// @lc code=start
class Solution { // Independently solved (hinted)
public:
    int longestArithSeqLength(vector<int>& nums) {
        const size_t size(nums.size());
        int** dp = new int*[size];
        for (size_t i(0); i < size; ++i) {
            dp[i] = new int[1010];
            int* curr(dp[i]);
            for (size_t j(0); j < 1010; ++j) {
                curr[j] = 0;
            }
        }
        int ans(0);
        for (size_t i(1); i < size; ++i) {
            int curr(nums.at(i));
            int* curr_dp(dp[i]);
            for (size_t j(0); j < i; ++j) {
                int diff(curr - nums.at(j));
                const int* prev_dp(dp[j]);
                curr_dp[diff + 500] = prev_dp[diff + 500] + 1;
                if (curr_dp[diff + 500] > ans) {
                    ans = curr_dp[diff + 500];
                }
            }
        }

        for (size_t i(0); i < size; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        return ans + 1;
    }
};
// @lc code=end