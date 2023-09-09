class Solution { // Independently solved
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long> dp_v(target + 1, 0);
        // if (target == 999) return 0;
        sort(nums.begin(), nums.end());
        long* dp(dp_v.data());
        dp[0] = 1;
        const int nums_size(nums.size());
        for (int i(1); i <= target; ++i) {
            long& curr_dp(dp[i]);
            for (int num_idx(0); num_idx < nums_size; ++num_idx) {
                int num(nums.at(num_idx));
                if (num > i) {
                    break;
                }
                curr_dp = ((long)curr_dp + dp[i - num]) % 2147483647;
            }
        }
        return dp[target];
    }
};