/*
 * @lc app=leetcode id=948 lang=cpp
 *
 * [948] Bag of Tokens
 *
 * https://leetcode.com/problems/bag-of-tokens/description/
 *
 * algorithms
 * Medium (46.30%)
 * Likes:    790
 * Dislikes: 303
 * Total Accepted:    41.7K
 * Total Submissions: 89.9K
 * Testcase Example:  '[100]\n50'
 *
 * You have an initial power of power, an initial score of 0, and a bag of
 * tokens where tokens[i] is the value of the i^th token (0-indexed).
 * 
 * Your goal is to maximize your total score by potentially playing each token
 * in one of two ways:
 * 
 * 
 * If your current power is at least tokens[i], you may play the i^th token
 * face up, losing tokens[i] power and gaining 1 score.
 * If your current score is at least 1, you may play the i^th token face down,
 * gaining tokens[i] power and losing 1 score.
 * 
 * 
 * Each token may be played at most once and in any order. You do not have to
 * play all the tokens.
 * 
 * Return the largest possible score you can achieve after playing any number
 * of tokens.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: tokens = [100], power = 50
 * Output: 0
 * Explanation: Playing the only token in the bag is impossible because you
 * either have too little power or too little score.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: tokens = [100,200], power = 150
 * Output: 1
 * Explanation: Play the 0^th token (100) face up, your power becomes 50 and
 * score becomes 1.
 * There is no need to play the 1^st token since you cannot play it face up to
 * add to your score.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: tokens = [100,200,300,400], power = 200
 * Output: 2
 * Explanation: Play the tokens in this order to get a score of 2:
 * 1. Play the 0^th token (100) face up, your power becomes 100 and score
 * becomes 1.
 * 2. Play the 3^rd token (400) face down, your power becomes 500 and score
 * becomes 0.
 * 3. Play the 1^st token (200) face up, your power becomes 300 and score
 * becomes 1.
 * 4. Play the 2^nd token (300) face up, your power becomes 0 and score becomes
 * 2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= tokens.length <= 1000
 * 0 <= tokens[i], power < 10^4
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens), end(tokens));
        const int kSize = tokens.size();
        int curr_pow = power;
        int head = 0;
        int tail = kSize - 1;
        int score = 0;
        while (head <= tail) {
            while (head < kSize && curr_pow >= tokens.at(head)) {
                curr_pow -= tokens.at(head);
                score += 1;
                // cout << head << ' ';
                head++;
            }
            if (head < tail && score > 0) {
                curr_pow += tokens.at(tail);
                score -= 1;
            } else {
                break;
            }
            // cout << tail << '\n';
            tail--;
        }
        return score;
    }
};
// @lc code=end

