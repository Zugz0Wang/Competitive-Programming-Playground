/*
 * @lc app=leetcode id=2218 lang=cpp
 *
 * [2218] Maximum Value of K Coins From Piles
 *
 * https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/
 *
 * algorithms
 * Hard (49.10%)
 * Likes:    1587
 * Dislikes: 25
 * Total Accepted:    36K
 * Total Submissions: 61.7K
 * Testcase Example:  '[[1,100,3],[7,8,9]]\n2'
 *
 * There are n piles of coins on a table. Each pile consists of a positive
 * number of coins of assorted denominations.
 * 
 * In one move, you can choose any coin on top of any pile, remove it, and add
 * it to your wallet.
 * 
 * Given a list piles, where piles[i] is a list of integers denoting the
 * composition of the i^th pile from top to bottom, and a positive integer k,
 * return the maximum total value of coins you can have in your wallet if you
 * choose exactly k coins optimally.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: piles = [[1,100,3],[7,8,9]], k = 2
 * Output: 101
 * Explanation:
 * The above diagram shows the different ways we can choose k coins.
 * The maximum total we can obtain is 101.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k =
 * 7
 * Output: 706
 * Explanation:
 * The maximum total can be obtained if we choose all coins from the last
 * pile.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == piles.length
 * 1 <= n <= 1000
 * 1 <= piles[i][j] <= 10^5
 * 1 <= k <= sum(piles[i].length) <= 2000
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) { // Mostly independently solved
        const int piles_size(piles.size());
        for (int pile_idx(0); pile_idx < piles_size; ++pile_idx) {
            
            vector<int>& pile(piles.at(pile_idx));
            const int pile_size(pile.size());

            for (int i(1); i < pile_size; ++i) {
                pile.at(i) += pile.at(i - 1);
            }
        }

        vector<vector<int>> dp(piles_size, vector<int>(k + 1, 0));
        int pile_size(piles.at(0).size());
        int all(0);
        for (int c(1); c < k + 1; ++c) {
            if (c > pile_size) {
                break;
            } else {
                dp.at(0).at(c) = piles.at(0).at(c - 1);
            }
        }
        all = pile_size;
        for (int pile_idx(1); pile_idx < piles_size; ++pile_idx) {
            vector<int>& prev(dp.at(pile_idx - 1));
            vector<int>& curr(dp.at(pile_idx));
            vector<int>& pile(piles.at(pile_idx));
            const int pile_size(pile.size());
            int new_all = all + pile_size;
            for (int c(1); c <= min(new_all, k); ++c) { // This optimization is my independent idea
                int m(prev.at(c));
                for (int i(min(c - 1, pile_size - 1)); i >= 0; --i) { // Got hint from solution with the min here
                    int idx(i);
                    if (i >= pile_size) {
                        idx = pile_size - 1;
                    }
                    int prev_c(c - idx - 1);
                    if (prev_c > all) {
                        break;
                    }
                    if (pile.at(idx) + prev.at(prev_c) > m) {
                        m = pile.at(idx) + prev.at(prev_c);
                    }
                }
                curr.at(c) = m;
            }
            all += pile_size;
        }
       
        return dp.at(piles_size - 1).at(k);
    }
};

// @lc code=end

