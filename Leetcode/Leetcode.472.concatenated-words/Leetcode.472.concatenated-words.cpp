/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 *
 * https://leetcode.com/problems/concatenated-words/description/
 *
 * algorithms
 * Hard (44.38%)
 * Likes:    2406
 * Dislikes: 239
 * Total Accepted:    159.9K
 * Total Submissions: 347.3K
 * Testcase Example:  '["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]'
 *
 * Given an array of strings words (without duplicates), return all the
 * concatenated words in the given list of words.
 * 
 * A concatenated word is defined as a string that is comprised entirely of at
 * least two shorter words in the given array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words =
 * ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
 * Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
 * Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 * "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
 * "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["cat","dog","catdog"]
 * Output: ["catdog"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 10^4
 * 1 <= words[i].length <= 30
 * words[i] consists of only lowercase English letters.
 * All the strings of words are unique.
 * 1 <= sum(words[i].length) <= 10^5
 * 
 * 
 */
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    //Adapted from Offical solution
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> ans;
        for (const string& word : words) {
            const int kLength = word.length();
            vector<bool> dp(kLength + 1, false);
            dp.at(0) = true;
            for (int i = 1; i <= kLength; i++) {
                int j = 0;
                if (i == kLength) {
                    j = 1;
                }
                for (; dp.at(i) == false && j < i; j++) {
                    dp.at(i) = dp.at(j) && (dict.count(word.substr(j, i - j)) > 0);
                }
                if (dp.at(kLength)) {
                    ans.push_back(word);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

