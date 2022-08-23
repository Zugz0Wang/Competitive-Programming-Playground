/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 *
 * https://leetcode.com/problems/stone-game-ii/description/
 *
 * algorithms
 * Medium (64.78%)
 * Likes:    1456
 * Dislikes: 268
 * Total Accepted:    42.1K
 * Total Submissions: 65K
 * Testcase Example:  '[2,7,9,4,4]'
 *
 * Alice and Bob continue their games with piles of stones.  There are a number
 * of piles arranged in a row, and each pile has a positive integer number of
 * stones piles[i].  The objective of the game is to end with the most
 * stones. 
 * 
 * Alice and Bob take turns, with Alice starting first.  Initially, M = 1.
 * 
 * On each player's turn, that player can take all the stones in the first X
 * remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).
 * 
 * The game continues until all the stones have been taken.
 * 
 * Assuming Alice and Bob play optimally, return the maximum number of stones
 * Alice can get.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: piles = [2,7,9,4,4]
 * Output: 10
 * Explanation:  If Alice takes one pile at the beginning, Bob takes two piles,
 * then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total.
 * If Alice takes two piles at the beginning, then Bob can take all three piles
 * left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10
 * since it's larger. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: piles = [1,2,3,4,5,100]
 * Output: 104
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= piles.length <= 100
 * 1 <= piles[i] <= 10^4
 * 
 * 
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int kSize = 0;
    int dp[100][200];
    int suffix_sum[100];
    vector<int> piles_g;
    int dfs(int idx, int m) {
        if (idx >= kSize) {
            return 0;
        }
        if (dp[idx][m] != -1) {
            return dp[idx][m];
        }
        if (idx + (m * 2) >= kSize) { // Can take all
            return suffix_sum[idx];
        }
        
        int max_sum = 0;
        int sum = 0;
        for (int take = 0; take < 2 * m; take++) {
            sum += piles_g.at(idx + take);
            // cout << sum << ' ';
            int next_idx = idx + take + 1;
            int oppoent = dfs(next_idx, max(m, take + 1));
            int curr_sum = sum + suffix_sum[next_idx] - oppoent;
            
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
            }
        }
        dp[idx][m] = max_sum;
        return max_sum;
    }
    int stoneGameII(vector<int>& piles) {
        kSize = piles.size();
        piles_g = piles;
        suffix_sum[kSize - 1] = piles.at(kSize - 1);
        for (int i = kSize - 2; i >= 0; i--) {
            suffix_sum[i] = suffix_sum[i + 1] + piles.at(i);
        }
        memset(dp, -1, sizeof(dp));
        return dfs(0, 1);
    }
};
// @lc code=end

