/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (56.26%)
 * Likes:    2826
 * Dislikes: 355
 * Total Accepted:    536K
 * Total Submissions: 932.5K
 * Testcase Example:  '"a"\n"b"'
 *
 * Given two strings ransomNote and magazine, return true if ransomNote can be
 * constructed by using the letters from magazine and false otherwise.
 * 
 * Each letter in magazine can only be used once in ransomNote.
 * 
 * 
 * Example 1:
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 * Example 2:
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 * Example 3:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote and magazine consist of lowercase English letters.
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int dict[26];
    bool canConstruct(string ransomNote, string magazine) {
        memset(dict, 0, sizeof(dict));
        const int kLengthR = ransomNote.length();
        const int kLengthM = magazine.length();
        if (kLengthR > kLengthM) {
            return false;
        }
        for (char i : magazine) {
            dict[i - 'a'] += 1;
        }
        for (char i : ransomNote) {
            if (dict[i - 'a'] > 0) {
                dict[i - 'a'] -= 1;
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

