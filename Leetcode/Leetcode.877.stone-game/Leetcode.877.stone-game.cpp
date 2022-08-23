/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 *
 * https://leetcode.com/problems/stone-game/description/
 *
 * algorithms
 * Medium (69.47%)
 * Likes:    2208
 * Dislikes: 2192
 * Total Accepted:    165.4K
 * Total Submissions: 238.1K
 * Testcase Example:  '[5,3,4,5]'
 *
 * Alice and Bob play a game with piles of stones. There are an even number of
 * piles arranged in a row, and each pile has a positive integer number of
 * stones piles[i].
 * 
 * The objective of the game is to end with the most stones. The total number
 * of stones across all the piles is odd, so there are no ties.
 * 
 * Alice and Bob take turns, with Alice starting first. Each turn, a player
 * takes the entire pile of stones either from the beginning or from the end of
 * the row. This continues until there are no more piles left, at which point
 * the person with the most stones wins.
 * 
 * Assuming Alice and Bob play optimally, return true if Alice wins the game,
 * or false if Bob wins.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: piles = [5,3,4,5]
 * Output: true
 * Explanation: 
 * Alice starts first, and can only take the first 5 or the last 5.
 * Say she takes the first 5, so that the row becomes [3, 4, 5].
 * If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10
 * points.
 * If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win
 * with 9 points.
 * This demonstrated that taking the first 5 was a winning move for Alice, so
 * we return true.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: piles = [3,7,2,3]
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= piles.length <= 500
 * piles.length is even.
 * 1 <= piles[i] <= 500
 * sum(piles[i]) is odd.
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    
    vector<vector<int>> dp;
    
    bool stoneGame(vector<int>& piles) {
        const int kSize = piles.size();
        vector<int> row(kSize + 1, 0);
        dp.assign(kSize + 1, row);
        // length = 1;
        for (int i = 0; i < kSize; i++) {
            dp.at(0).at(i) = -piles.at(i);
        }

        for (int length = 2; length <= kSize; length++) {
            for (int i = 0; i < kSize - length + 1; i++) {
                int head_val = piles.at(i);
                int tail_val = piles.at(i + length - 1);
                dp.at(length).at(i) = min(-(head_val + dp.at(length - 1).at(i + 1)),(-(tail_val + dp.at(length - 1).at(i))));
            }
        }
        return dp.at(kSize).at(0) < 0;
    }
};
// @lc code=end
// '[5,3,4,5]'
// '[5,3,4,3,6,5]'
