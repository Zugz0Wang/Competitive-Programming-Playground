class Solution { // Independently solved
public:
    size_t coins_size;
    int* coins;
    int* dp;
    int helper(int amount, int begin) {
        if (amount == 0) {
            return 1;
        }
        int& curr_dp(dp[amount * (coins_size) + begin]);
        if (curr_dp >= 0) {
            return curr_dp;
        }
        int ans(0);
        for (size_t i(begin); i < coins_size; ++i) {
            int coin(coins[i]);
            if (amount >= coin) {
                ans += helper(amount - coin, i);
            }
        }
        
        curr_dp = ans;
        return curr_dp;
    }
    int change(int amount, vector<int>& coins_) {
        coins_size = coins_.size();
        coins = coins_.data();
        vector<int> dp_v((amount + 1) * coins_size, -1);
        dp = dp_v.data();
        
        return helper(amount, 0);
    }
};