/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 *
 * https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/
 *
 * algorithms
 * Easy (81.30%)
 * Likes:    1125
 * Dislikes: 26
 * Total Accepted:    117.4K
 * Total Submissions: 143.9K
 * Testcase Example:  '"thequickbrownfoxjumpsoverthelazydog"'
 *
 * A pangram is a sentence where every letter of the English alphabet appears
 * at least once.
 * 
 * Given a string sentence containing only lowercase English letters, return
 * true if sentence is a pangram, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
 * Output: true
 * Explanation: sentence contains at least one of every letter of the English
 * alphabet.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: sentence = "leetcode"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= sentence.length <= 1000
 * sentence consists of lowercase English letters.
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool dict[26];
    bool checkIfPangram(string sentence) {
        memset(dict, false, sizeof(dict));
        int count = 0;
        for (char i : sentence) {
            if (dict[i - 'a'] == false) {
                count += 1;
                dict[i - 'a'] = true;
            }
            if (count == 26) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

