/*
 * @lc app=leetcode id=1406 lang=cpp
 *
 * [1406] Stone Game III
 *
 * https://leetcode.com/problems/stone-game-iii/description/
 *
 * algorithms
 * Hard (60.05%)
 * Likes:    1082
 * Dislikes: 23
 * Total Accepted:    39K
 * Total Submissions: 65K
 * Testcase Example:  '[1,2,3,7]'
 *
 * Alice and Bob continue their games with piles of stones. There are several
 * stones arranged in a row, and each stone has an associated value which is an
 * integer given in the array stoneValue.
 * 
 * Alice and Bob take turns, with Alice starting first. On each player's turn,
 * that player can take 1, 2, or 3 stones from the first remaining stones in
 * the row.
 * 
 * The score of each player is the sum of the values of the stones taken. The
 * score of each player is 0 initially.
 * 
 * The objective of the game is to end with the highest score, and the winner
 * is the player with the highest score and there could be a tie. The game
 * continues until all the stones have been taken.
 * 
 * Assume Alice and Bob play optimally.
 * 
 * Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they
 * will end the game with the same score.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: values = [1,2,3,7]
 * Output: "Bob"
 * Explanation: Alice will always lose. Her best move will be to take three
 * piles and the score become 6. Now the score of Bob is 7 and Bob wins.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: values = [1,2,3,-9]
 * Output: "Alice"
 * Explanation: Alice must choose all the three piles at the first move to win
 * and leave Bob with negative score.
 * If Alice chooses one pile her score will be 1 and the next move Bob's score
 * becomes 5. In the next move, Alice will take the pile with value = -9 and
 * lose.
 * If Alice chooses two piles her score will be 3 and the next move Bob's score
 * becomes 3. In the next move, Alice will take the pile with value = -9 and
 * also lose.
 * Remember that both play optimally so here Alice will choose the scenario
 * that makes her win.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: values = [1,2,3,6]
 * Output: "Tie"
 * Explanation: Alice cannot win this game. She can end the game in a draw if
 * she decided to choose all the first three piles, otherwise she will
 * lose.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= stoneValue.length <= 5 * 10^4
 * -1000 <= stoneValue[i] <= 1000
 * 
 * 
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int kSize = 0;
    int dp[50010], suffix[50010];
    bool dp_valid[50010];
    vector<int> stone_g;

    int DFS(int idx) {
        if (idx >= kSize) {
            return 0;
        }
        if (dp_valid[idx]) {
            return dp[idx];
        }
        int sum = 0;
        int max_sum = 0;
        bool start = false;
        for (int take = 0; take < 3 && (idx + take < kSize); take++) {
            sum += stone_g.at(idx + take);
            int next_idx = idx + take + 1;
            int final_sum = sum - DFS(next_idx);
            // cout << idx << ':' << final_sum << '\n';
            if (start) {
                if (final_sum > max_sum) {
                    max_sum = final_sum;
                }
            } else {
                max_sum = final_sum;
                start = true;
            }
            
        }
        dp_valid[idx] = true;
        dp[idx] = max_sum;
        return max_sum;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        stone_g = stoneValue;
        kSize = stone_g.size();
        // suffix[kSize] = 0;
        // suffix[kSize - 1] = stone_g.at(kSize - 1);
        // for (int i = kSize - 2; i >= 0; i--) {
        //     suffix[i] = suffix[i + 1] + stone_g.at(i);
        // }
        
        memset(dp_valid, false, sizeof(dp_valid));
        int result = DFS(0);
        // for (int i = 0; i < kSize; i++) {
        //     cout << dp[i] << ' ';
        // }
        if (result > 0) {
            return "Alice";
        } else if (result == 0) {
            return "Tie";
        } else {
            return "Bob";
        }
    }
};
// @lc code=end
// [1,2,3,-9]
// [-2]
