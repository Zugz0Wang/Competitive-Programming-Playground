/*
 * @lc app=leetcode id=1996 lang=cpp
 *
 * [1996] The Number of Weak Characters in the Game
 *
 * https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/description/
 *
 * algorithms
 * Medium (37.09%)
 * Likes:    2146
 * Dislikes: 70
 * Total Accepted:    66.2K
 * Total Submissions: 155.5K
 * Testcase Example:  '[[5,5],[6,3],[3,6]]'
 *
 * You are playing a game that contains multiple characters, and each of the
 * characters has two main properties: attack and defense. You are given a 2D
 * integer array properties where properties[i] = [attacki, defensei]
 * represents the properties of the i^th character in the game.
 * 
 * A character is said to be weak if any other character has both attack and
 * defense levels strictly greater than this character's attack and defense
 * levels. More formally, a character i is said to be weak if there exists
 * another character j where attackj > attacki and defensej > defensei.
 * 
 * Return the number of weak characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: properties = [[5,5],[6,3],[3,6]]
 * Output: 0
 * Explanation: No character has strictly greater attack and defense than the
 * other.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: properties = [[2,2],[3,3]]
 * Output: 1
 * Explanation: The first character is weak because the second character has a
 * strictly greater attack and defense.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: properties = [[1,5],[10,4],[4,3]]
 * Output: 1
 * Explanation: The third character is weak because the second character has a
 * strictly greater attack and defense.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= properties.length <= 10^5
 * properties[i].length == 2
 * 1 <= attacki, defensei <= 10^5
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
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a.at(0) == b.at(0)) {
            return a.at(1) < b.at(1);
        } else {
            return a.at(0) > b.at(0);
        }
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        const int kSize = properties.size();
        sort(properties.begin(), properties.end(), compare);
        bool start = false;
        int mx = 0;
        int count = 0;
        for (int i = 0; i < kSize; i++) {
            int curr = properties.at(i).at(1);
            // cout << properties.at(i).at(0) << '\n';
            if (start) {
                if (curr < mx) {
                    count++;
                } else if (curr > mx) {
                    mx = curr;
                }
            } else {
                mx = curr;
                start = true;
            }
        }
        return count;
    }
};
// @lc code=end

