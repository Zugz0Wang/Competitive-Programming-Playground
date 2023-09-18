class Solution { // Learned from solution??
public:
    size_t idx(size_t len, size_t mx, size_t cost, size_t N, size_t M, size_t K) {
        return len * M * K + mx * K + cost;
    }
    int numOfArrays(int n, int m, int k) {
        const size_t N(n + 1);
        const size_t M(m + 1);
        const size_t K(k + 1);
        const int mod(1e9 + 7);
        vector<int> dp_v(N * M * K, 0);
        vector<int> pre_v(N * M * K, 0);
        int* dp(dp_v.data());
        int* pre(pre_v.data());
        for (size_t mx(0); mx < M; ++mx) {
            size_t i(idx(1, mx, 1, N, M, K));
            dp[i] = 1;
            pre[i] = mx;
        }

        for (size_t len(2); len < N; ++len) {
            for (size_t mx(1); mx < M; ++mx) {
                for (size_t cost(1); cost < K; ++cost) {
                    size_t curr_dp_i(idx(len, mx, cost, N, M, K));
                    int curr_dp((1LL * mx * dp[idx(len - 1, mx, cost, N, M, K)]) % mod);

                    curr_dp = (curr_dp + pre[idx(len - 1, mx - 1, cost - 1, N, M, K)]) % mod;

                    pre[curr_dp_i] = (pre[idx(len, mx - 1, cost, N, M, K)] + curr_dp) % mod;
                    dp[curr_dp_i] = curr_dp;
                }
            }
        }
        return pre[idx(n, m, k, N, M, K)];
    }
};