/*
 * @lc app=leetcode id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 *
 * https://leetcode.com/problems/best-team-with-no-conflicts/description/
 *
 * algorithms
 * Medium (41.06%)
 * Likes:    1204
 * Dislikes: 36
 * Total Accepted:    27.4K
 * Total Submissions: 63.4K
 * Testcase Example:  '[1,3,5,10,15]\n[1,2,3,4,5]'
 *
 * You are the manager of a basketball team. For the upcoming tournament, you
 * want to choose the team with the highest overall score. The score of the
 * team is the sum of scores of all the players in the team.
 * 
 * However, the basketball team is not allowed to have conflicts. A conflict
 * exists if a younger player has a strictly higher score than an older player.
 * A conflict does not occur between players of the same age.
 * 
 * Given two lists, scores and ages, where each scores[i] and ages[i]
 * represents the score and age of the i^th player, respectively, return the
 * highest overall score of all possible basketball teams.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
 * Output: 34
 * Explanation: You can choose all the players.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: scores = [4,5,6,5], ages = [2,1,2,1]
 * Output: 16
 * Explanation: It is best to choose the last 3 players. Notice that you are
 * allowed to choose multiple people of the same age.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: scores = [1,2,3,5], ages = [8,9,10,1]
 * Output: 6
 * Explanation: It is best to choose the first 3 players. 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= scores.length, ages.length <= 1000
 * scores.length == ages.length
 * 1 <= scores[i] <= 10^6
 * 1 <= ages[i] <= 1000
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    // Learned from solution and independently solved.
    // The main reason for sorting is to avoid invalid selections like (2,5),(1,1),(3,4) 
    int dp[1000];
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        const int kSize = scores.size();
        vector<pair<int, int>> players(kSize);
        for (int i = 0; i < kSize; i++) {
            players.at(i) = {ages.at(i), scores.at(i)};
        }
        sort(players.begin(), players.end());
        for (int i = 0; i < kSize; i++) {
            int i_age = players.at(i).first;
            int i_score = players.at(i).second;
            dp[i] = i_score;
            for (int j = 0; j < i; j++) {
                int j_age = players.at(j).first;
                int j_score = players.at(j).second;
                if ((i_age == j_age || j_score <= i_score)
                    && dp[i] < i_score + dp[j]) {
                    dp[i] = i_score + dp[j];
                }
            }
        }
        int max = 0;
        for (int i = 0; i < kSize; i++) {
            if (dp[i] > max) {
                max = dp[i];
            }
        }
        return max;
    }
};
//[4,5,6,5]\n[2,1,2,1]
// @lc code=end

