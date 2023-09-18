class Solution {
public:
    int integerBreak(int n) {
        static int size(59);
        vector<int> dp_v(n + 1, 1);
        int* dp(dp_v.data());
        
        dp[2] = 1;
        for (int i(3); i <= n; ++i) {
            int& curr_dp(dp[i]);
            curr_dp = (i - 1);
            dp[i - 1] = max(dp[i - 1], i - 1);
            for (int j(2); j <= (i / 2) + 1; ++j) {
                int curr(dp[j] * dp[i - j]);
                if (curr > curr_dp) {
                    curr_dp = curr;
                }
            }
        }
        return dp[n];
    }
};