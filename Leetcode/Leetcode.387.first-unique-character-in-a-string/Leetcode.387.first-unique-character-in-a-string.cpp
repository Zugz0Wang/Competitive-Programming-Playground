/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (57.71%)
 * Likes:    6223
 * Dislikes: 220
 * Total Accepted:    1.2M
 * Total Submissions: 2M
 * Testcase Example:  '"leetcode"'
 *
 * Given a string s, find the first non-repeating character in it and return
 * its index. If it does not exist, return -1.
 * 
 * 
 * Example 1:
 * Input: s = "leetcode"
 * Output: 0
 * Example 2:
 * Input: s = "loveleetcode"
 * Output: 2
 * Example 3:
 * Input: s = "aabb"
 * Output: -1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of only lowercase English letters.
 * 
 * 
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        vector<bool> exists(26);
        vector<bool> repeat(26);
        for (char c : s) {
            int idx = c - 'a';
            if (exists.at(idx) == true) {
                repeat.at(idx) = true;
            } else {
                exists.at(idx) = true;
            }
        }
        const int kLength = s.length();
        for (int i = 0; i < kLength; i++) {
            int idx = s.at(i) - 'a';
            if (repeat.at(idx) == false) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

