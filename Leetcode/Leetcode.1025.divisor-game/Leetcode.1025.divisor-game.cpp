/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 *
 * https://leetcode.com/problems/divisor-game/description/
 *
 * algorithms
 * Easy (66.94%)
 * Likes:    1485
 * Dislikes: 3374
 * Total Accepted:    171.1K
 * Total Submissions: 255.5K
 * Testcase Example:  '2'
 *
 * Alice and Bob take turns playing a game, with Alice starting first.
 * 
 * Initially, there is a number n on the chalkboard. On each player's turn,
 * that player makes a move consisting of:
 * 
 * 
 * Choosing any x with 0 < x < n and n % x == 0.
 * Replacing the number n on the chalkboard with n - x.
 * 
 * 
 * Also, if a player cannot make a move, they lose the game.
 * 
 * Return true if and only if Alice wins the game, assuming both players play
 * optimally.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: true
 * Explanation: Alice chooses 1, and Bob has no more moves.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3
 * Output: false
 * Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more
 * moves.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 1000
 * 
 * 
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp_table(n + 1, false);
        dp_table.at(1) = false;
        for (int i = 2; i <= n; i++) {
            for (int j = i - 1; j > 0; j--) {
                int diff = i - j;
                if (i % diff == 0 && dp_table.at(j) == false) {
                    dp_table.at(i) = true;
                    break;
                }
            }
            
        }
        return dp_table.at(n);
    }
};
// @lc code=end

