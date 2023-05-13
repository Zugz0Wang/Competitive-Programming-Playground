// @lc app=leetcode id=2466 lang=cpp
#include <vector>
using namespace std;
// @lc code=start
class Solution { // Independently solved
public:
    int* dp;
    int zero;
    int one;
    int mod = 1e9+7;
    int search(int i) {
        if (i < 0) {
            return 0;
        } else if (dp[i] > -1) {
            return dp[i];
        }

        dp[i] = (search(i - zero) + search(i - one)) % mod;
        return dp[i];
    }

    int countGoodStrings(int low, int high, int zero_, int one_) {
        zero = zero_;
        one = one_;
        dp = new int[high + 1];
        for (int i(0); i <= high; ++i) {
            dp[i] = -1;
        }
        dp[0] = 1;
        int count(0);
        for (int i(low); i <= high; ++i) {
            count = (count + search(i)) % mod;
        }
        delete[] dp;
        return count;
    }
};
// @lc code=end