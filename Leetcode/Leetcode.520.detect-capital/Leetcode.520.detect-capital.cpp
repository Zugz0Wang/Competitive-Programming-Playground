/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (55.67%)
 * Likes:    1881
 * Dislikes: 384
 * Total Accepted:    286.9K
 * Total Submissions: 515.8K
 * Testcase Example:  '"USA"'
 *
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 * 
 * 
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital, like "Google".
 * 
 * 
 * Given a string word, return true if the usage of capitals in it is right.
 * 
 * 
 * Example 1:
 * Input: word = "USA"
 * Output: true
 * Example 2:
 * Input: word = "FlaG"
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word.length <= 100
 * word consists of lowercase and uppercase English letters.
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        const int kLength = word.length();
        for (char c : word) {
            if (c >= 'A' && c <= 'Z') {
                count += 1;
            }
        }
        if (count == 1 && word.at(0) >= 'A' && word.at(0) <= 'Z') {
            return true;
        } else if (count == kLength || count == 0) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end

