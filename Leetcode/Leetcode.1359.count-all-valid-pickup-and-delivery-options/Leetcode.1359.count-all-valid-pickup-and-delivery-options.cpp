class Solution { // Independently solved
public:
    int sum_helper(int n) {
        return ((n + 1) * n) / 2;
    }
    int mod = 1e9 + 7;
    int countOrders(int n) {
        if (n == 1) {
            return 1;
        }
        int prev(1);
        for (int i(2); i <= n; ++i) {
            prev = ((long)prev * sum_helper((i - 1) * 2 + 1)) % mod;
        }
        return prev;
    }
};